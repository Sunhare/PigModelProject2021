%% S1S2 Array Initialization 

clear all;
close all;
%% S1S2 Simulation
% stored_t = false;

s2_array = [200:5:500];
s2_v_array = zeros(2000, length(s2_array));


for cell_type = 1:3

% Load Parameters
const_params = [1000;0;150;0.1;1;1;1;cell_type;-1];

if cell_type == 1
    cell_name = "control";
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/CONTROL_PARAMS_FINAL.mat"));
elseif cell_type == 2
    cell_name = "remote";
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/REMOTE_HF_PARAMS_FINAL.mat"));
elseif cell_type == 3
    cell_name = "border";
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/BORDER_HF_PARAMS_FINAL.mat"));
end


tic
parfor i=1:length(s2_array)
    s2_pcl_loop = s2_array(i);
    
    all_params = [const_params; scaling_parameters];
    all_params(9) = s2_pcl_loop;
    total_error = PIG_COST_FUNCTION(all_params, false);
    
    fileNAME= './outputs/S1S2/'+string(cell_name)+'_results_'+string(1000)+'_s2_'+string(s2_pcl_loop)+'.txt';
    fileID = fopen(fileNAME,'r');
    ion_sim_data_s1s2 = textscan(fileID, strjoin(repelem("%f ", 2))+"%*[^\n]", 'Delimiter','\t');
    ion_sim_data_s1s2 = cell2mat(ion_sim_data_s1s2);

    v_s2 = ion_sim_data_s1s2(:,2)
    s2_v_array(:,i) = v_s2;

end
save("./outputs/PRISM_DATA/BACKUP_S1S2_"+cell_name+".mat", "s2_v_array")
end
toc


%% 
for i = 1:3
    figure
    if i == 1
        load("./outputs/PRISM_DATA/BACKUP_S1S2_Control.mat");
        color = [0 0 0 0.6];
    elseif i == 2
        load("./outputs/PRISM_DATA/BACKUP_S1S2_remote.mat");
        color = [0 1 0 0.6];
    elseif i == 3
        load("./outputs/PRISM_DATA/BACKUP_S1S2_border.mat");
        color = [1 0 0 0.6];
    end
    t_s1s2 = linspace(0,2000,2000);
    plot(t_s1s2, s2_v_array(:,:), 'Color', color)
    xlim([0 800])
end

%% S1S2 Array Initialization 

s1_apd_array = [];
s2_apd_array = [];
s1_di_array = [];
%% S1S2 Detailed Analysis (Stim Current)
%Requires exactly last 2 beats in data file

paths1s2 = "./outputs/S1S2/";
for cell_type= 1:3
    if cell_type == 1
        cell_name = "control";
    elseif cell_type == 2
        cell_name = "remote";
    elseif cell_type == 3
        cell_name = "border";
    end
    fprintf("%s S1S2\n", capitalize(cell_name))
    s1s2_files = dir(paths1s2+cell_name+"_results_"+string(1000)+"_s2_*");
    one = struct2table(s1s2_files);
    two = table2cell(one);
    n_s1s2 = cell2mat(two(2:end,1));

    parfor i=1:size(n_s1s2,1)
%     for i = 140
        fprintf("S1S2_%s: %d/%d\n", cell_name, i, size(n_s1s2,1));
        fileNAME= paths1s2+n_s1s2(i,:);
        fileID = fopen(fileNAME,'r');
        data_s1s2 = textscan(fileID, strjoin(repelem("%f ", 21))+"%*[^\n]", 'Delimiter','\t');
        data_s1s2 = cell2mat(data_s1s2);
        
        t_s1s2 = data_s1s2(:,1)-data_s1s2(1,1);
        v_s1s2 = data_s1s2(:,2);
        istim_s1s2 = data_s1s2(:,21);
        
        v_s1s2_array(:,i) = v_s1s2;
        istim_array(:,i) = istim_s1s2;
        
        
        [val, stim_ind] = findpeaks(istim_s1s2);
        
        apd1_s1s2 = calc_apd95([t_s1s2(1:stim_ind-1) v_s1s2(1:stim_ind-1)]);
        s1_apd_array(i) = apd1_s1s2;
        apd2_s1s2 = calc_apd95([t_s1s2(stim_ind:end) v_s1s2(stim_ind:end)]);
        s2_apd_array(i)= apd2_s1s2;

        s1_di_array(i) = t_s1s2(stim_ind)-apd1_s1s2;

    end
    s1s2_prism = [s1_di_array; s2_apd_array]';
    s1s2_fout_name = strcat('./outputs/PRISM_DATA/','s1s2_',string(cell_name),'.txt');
    save(s1s2_fout_name, 's1s2_prism', '-ascii','-tabs')
end

%% Plot S1S2 Restitution Curve

% plot(t_s1s2(1:stim_ind), v_s1s2(1:stim_ind), 'LineWidth', 2)
% plot(t_s1s2(stim_ind:end), v_s1s2(stim_ind:end), 'LineWidth', 2)
set(gcf, 'Color', 'white')
% plot(s1_apd_array, s2_apd_array, 'ok','LineWidth',2, 'MarkerSize', 20, 'MarkerFaceColor', 'k')
plot(s1_di_array, s2_apd_array, 'ok','LineWidth',2, 'MarkerSize', 20, 'MarkerFaceColor', 'r')
% plot(s1s2_prism)
xlabel("S1 DI (ms)")
ylabel("S2 APD95 (ms)")
set(gca, 'FontSize', 30)

%% Calculate APD at 95% repolarization Function
function apd95 = calc_apd95(t_v)
    n = length(t_v);
    
    max_v = max(t_v(:,2));
    min_v = min(t_v(:,2));
    amp = max_v - min_v;
    v95 = max_v - (0.95*amp);
    
    t1 = 0;
    t2 = 0;
    t1_bool = false;
    t2_bool = false;
    
    for i = 2:n 
        if(t_v(i,1) > 5 && t_v(i,2) > v95 && t_v(i-1, 2) < v95 && t1_bool == false)
            t1 = t_v(i,1);
            t1_bool = true;
        end
        if(t_v(i,1) > 15 && t_v(i,2) < v95 && t_v(i-1, 2) > v95 && t2_bool == false)
            t2 = t_v(i,1);
            t2_bool = true;
        end
            
    end
    
    if(t1_bool && t2_bool)
        apd95 = t2-t1;

    elseif t2_bool == false
        apd95 = t_v(end,1)-t1;
    elseif t1_bool == false
        apd95 = t2-t_v(1,1);
    else
        apd95 = t2-t1;
        fprintf("Error: Strange Case found in APD95 calculation")
    end
    
    if t1 > t2
        fprintf("Error: Negative APD (t1: %.2f, t2: %.2f)", t1, t2)
    end
end

function cap_str = capitalize(in_str)
    cap_str = regexprep(in_str,'(\<[a-z])','${upper($1)}');

end