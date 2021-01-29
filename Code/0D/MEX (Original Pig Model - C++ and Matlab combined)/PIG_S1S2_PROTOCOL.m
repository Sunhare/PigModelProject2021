%% S1S2 Array Initialization 


s1_apd_array = [];
s2_apd_array = [];

%% S1S2 Simulation
stored_t = false;
s2_v_array = [];

figure
hold on
s2_array = [200:10:1000];

for i=1:length(s2_array)
    s2_pcl_loop = s2_array(i);
    all_params(9) = s2_pcl_loop;
    total_error = PIG_COST_FUNCTION(all_params, false);
    
    ion_sim_data = load('./outputs/results/'+string(cell_name)+'_results_'+string(floor(pcl))+'_s2_'+string(s2_pcl_loop)+'.txt');
    if stored_t == false
        t_s2 = ion_sim_data(:,1);
        stored_t = true;
    end
    v_s2 = ion_sim_data(:,2);
    s2_v_array = [s2_v_array v_s2];

    plot(t_s2, v_s2, 'r', 'LineWidth', 2)
end

%% Plot S1S2 (V vs T)
figure(1)
set(gcf, 'Color', 'white')
plot(t_s2-t_s2(1), s2_v_array(:, :), 'r', 'LineWidth', 2);
xlim([0 1000])
xlabel("Time (ms)")
ylabel("Voltage (mV")
set(gca, 'FontSize', 50)
title("S1S2 Pacing of "+upper(string(cell_name))+ " Cell")


%% S1S2 Array Initialization 
% s2_v_array = [];

s1_apd_array = [];
s2_apd_array = [];
s1_di_array = [];
%% S1S2 Detailed Analysis (Stim Current)
%Requires exactly last 2 beats in data file

% figure
% set(gcf, 'Color', 'White')
% hold on
paths1s2 = "outputs/results/";
for cell_type=3
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

    for i=1:size(n_s1s2,1)
        fprintf("S1S2: %d/%d\n", i, size(n_s1s2,1));
        data_s1s2 = load(paths1s2+n_s1s2(i,:));
        t_s1s2 = data_s1s2(:,1)-data_s1s2(1,1);
        v_s1s2 = data_s1s2(:,2);
        istim_s1s2 = data_s1s2(:,21);
        [val, stim_ind] = findpeaks(istim_s1s2);
        apd1_s1s2 = calc_apd95([t_s1s2(1:stim_ind-1) v_s1s2(1:stim_ind-1)]);
        s1_apd_array = [s1_apd_array apd1_s1s2];
        apd2_s1s2 = calc_apd95([t_s1s2(stim_ind:end) v_s1s2(stim_ind:end)]);
        s2_apd_array = [s2_apd_array apd2_s1s2];

        s1_di_array = [s1_di_array t_s1s2(stim_ind)-apd1_s1s2];

%         subplot 211
%         hold on
%         plot(t_s1s2, v_s1s2, 'LineWidth', 2)
% 
%         subplot 212
%         hold on
%         plot(t_s1s2, istim_s1s2, 'LineWidth', 2)
    end
    s1s2_prism = [s1_di_array; s2_apd_array]';
    s1s2_fout_name = strcat('./Prism_Data/','s1s2_',string(cell_name),'.txt');
    save(s1s2_fout_name, 's1s2_prism', '-ascii','-tabs')
end

%% Plot S1S2 Restitution Curve

% plot(t_s1s2(1:stim_ind), v_s1s2(1:stim_ind), 'LineWidth', 2)
% plot(t_s1s2(stim_ind:end), v_s1s2(stim_ind:end), 'LineWidth', 2)
set(gcf, 'Color', 'white')
% plot(s1_apd_array, s2_apd_array, 'ok','LineWidth',2, 'MarkerSize', 20, 'MarkerFaceColor', 'k')
plot(s1_di_array, s2_apd_array, 'ok','LineWidth',2, 'MarkerSize', 20, 'MarkerFaceColor', 'r')
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