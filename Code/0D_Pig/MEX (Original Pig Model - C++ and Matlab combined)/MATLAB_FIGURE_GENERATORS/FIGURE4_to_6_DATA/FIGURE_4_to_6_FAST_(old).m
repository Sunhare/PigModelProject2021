clear all;
close all;
% cd /Users/satolab/Desktop/ShannonPigModel/Bence_Data/Processed_DATA_Electrophysiology

output_root = '/Users/satolab/Desktop/ShannonPigModel/Cpp_files/Figures/exp_ion_traces/';
peak_ion_store = [];
peak_ion_store_names = ["INa", "INCX", "ICa", "IK1", "IKr", "IKs", "IKCa", "ICl"];
title_ion_store_names = ["I_N_a_L", "I_N_C_X", "I_C_a", "I_K_1", "I_K_r", "I_K_s", "I_K_C_a", "I_C_l"];


remote = ["150615BEN02","150615BEN03","150615BEN04","150615BEN05","150616BEN01","150616BEN02","150901BEN03","150902BEN01","150925BEN01","150925BEN02","150925BEN04","150925BEN07","150925BEN08","150925BEN09","150925BEN10","150925BEN11","150928BEN01","150928BEN02","150928BEN03","150928BEN05","150928BEN06","150929BEN01","150929BEN03","150929BEN04","150929BEN05","151001BEN01","151008BEN01","151008BEN02"];
border = ["150901BEN01","150901BEN06","150901BEN07","150902BEN02","150925BEN05","150928BEN04","151001BEN02","151001BEN03","151001BEN04","151008BEN03","151008BEN04","151008BEN05","151008BEN06","151008BEN07","151008BEN08","151008BEN09","151008BEN10","151009BEN02","151009BEN03","151009BEN04","151009BEN05","151009BEN06","151021BEN03"];

% % % % % % % 

data_peak = {}; %Used for Prism output
data_peak_sim = {};



%INa, INCX, ICa, IK1, IKr, IKs, IKCa, ICl
%Only calculate peak after a certain point to avoid capacitative weirdness
min_t_array = [20, 7, 10, 50, 40, 27, 7, 6.6;
               20, 10, 10, 50, 50, 50, 50, 8.42;
               20, 10, 10, 50, 50, 50, 50, 8.42;
               ]; 
           
y_lim_mat = [ [-0.8 0.2]; [-1.6 0.65]; [-4 0.65];
              [-0.5 3.2]; [-0.5 1.50]; [-0.1 0.5];
              [-0.1 0.6]; [-1 3.5]
              ];

control_exp_ions_total = {};
remote_exp_ions_total = {};
border_exp_ions_total = {};
%% 
tic
for cell_type=1:3
% for cell_type=1
    if cell_type == 1
        cell_name = "Control"
        root = "/Users/satolab/Desktop/ShannonPigModel/Bence_Data/Processed_DATA_Electrophysiology/AP-clamp_Control/";
    elseif cell_type == 2
        root = "/Users/satolab/Desktop/ShannonPigModel/Bence_Data/Processed_DATA_Electrophysiology/AP-clamp_HF/";
        cell_name = "Remote"
    elseif cell_type == 3
        root = "/Users/satolab/Desktop/ShannonPigModel/Bence_Data/Processed_DATA_Electrophysiology/AP-clamp_HF/";
        cell_name = "Border"
    end
    
    %Simulation Data
    sim_data = load("/Users/satolab/Desktop/ShannonPigModel/Cpp_files/outputs/results/"+lower(cell_name+"_results_1000.txt"));
    t_sim = sim_data(:, 1);
    v_sim = sim_data(:, 2);
    t_v_sim = [t_sim v_sim];
    
    i_nal = sim_data(:,10);
    i_ncx = sim_data(:,19);
    i_cal = sim_data(:,11);
    i_k1  = sim_data(:,12);
    i_kr  = sim_data(:,13);
    i_ks  = sim_data(:,16);
    i_sk  = sim_data(:,17);
    i_cl  = sim_data(:,20);
    
    sim_ion_traces = [i_nal i_ncx i_cal i_k1 i_kr i_ks i_sk i_cl];
   
    for i = 1:length(peak_ion_store_names) %Loop through all ion suffixes
%     for i=1
       
        %Averaged currents for display purposes
        avg_in = 0;
        avg_out = 0;

        %Find file names
        if cell_type == 1
            raw_ions = dir(root+"/15*_"+peak_ion_store_names(i)+".xlsx");
            raw_ions = table2cell(struct2table(raw_ions));
            raw_ions = cell2mat(raw_ions(:,1));
        elseif cell_type == 2
            raw_ions = strcat(char(remote'),'_',peak_ion_store_names(i),'.xlsx');
        elseif cell_type == 3
            raw_ions = strcat(char(border'),'_',peak_ion_store_names(i),'.xlsx');
        end


        figure('Position', [0 0 750 500])
        set(gcf, 'Renderer', 'Painters')
        set(gcf, 'Color', 'White')
        hold on

        n = size(raw_ions,1); %Number of files
        %Loop through all files
        sorting_index = cell_type + 3*(i-1);
        data_peak{cell_type+(3*(i-1)),1} = peak_ion_store_names(i);
      
        for j=1:n
%         for j=1
            %Some files don't exist, try/catch error to not crash
%             continue; %FIXMEREMOVETHIS
            try
                %First sheet is time/ion data
                file_name = root+raw_ions(j,:);
                fprintf("%s\n", raw_ions(j,:));
                opts = detectImportOptions(file_name);
                ions_tmp = readtable(file_name, opts);
                ions_tmp = table2array(ions_tmp);
                
                

                %Second sheet is associated AP Clamp data
                opts.Sheet = 'AP';
                ap_tmp = readtable(file_name, opts);
                ap_tmp = table2array(ap_tmp);
                apd95 = calc_apd95(ap_tmp); %My function to calculate APD
                fprintf("APD95: %.2f\n", apd95);
                
                % % % % % % % % % % % % % % % % % % % % 
                %Shifting by capacitative weirdness
                ions_tmp(:,1) = (ions_tmp(:,1)-10)./apd95 * 100; %Normalize time to APD
                % % % % % % % % % % % % % % % % % % % % 

                %Dummy variable to not mess up original data
                v_tmp = ions_tmp(:,2);
                opac = 1/(1+exp((n-9)/35))+0.2; %Opacity of lines (scales with number of plots)
                
                
                % % % SAVING DATA FOR FASTER SIMS % % % %
                if cell_type == 1
                    control_exp_ions_total(i,j) = mat2cell(ions_tmp, size(ions_tmp,1),size(ions_tmp,2));
                elseif cell_type == 2
                    remote_exp_ions_total(i,j) = mat2cell(ions_tmp, size(ions_tmp,1),size(ions_tmp,2));
                elseif cell_type == 3
                    border_exp_ions_total(i,j) = mat2cell(ions_tmp, size(ions_tmp,1),size(ions_tmp,2));
                end
                % % % % % % % % % % % % % % % % % % % % 
                %Plot Experimental Data
                plot(ions_tmp(1:30:end,1), ions_tmp(1:30:end,2), 'Color', [1 0 0 opac]);
                % % % % % % % % % % % % % % % % % % % % 
                
                time_filter = (ions_tmp(:,1) >= min_t_array(cell_type, i));

                min_peak = min(v_tmp(time_filter)); 
                max_peak = max(v_tmp(time_filter));

                avg_in = avg_in + min_peak/n;
                avg_out = avg_out + max_peak/n;


                if i <= 3 %Inward peak
                    peak = min_peak;
                    data_peak{sorting_index,j+1} = peak;
                elseif i > 3 %Outward peak
                    peak = max_peak;
                    data_peak{sorting_index, j+1} = peak;
                end
                fprintf("Peak: %.2f\n", peak);


            catch ME
                errorMessage = sprintf('Error in function %s() at line %d.\n\nError Message:\n%s', ...
                ME.stack(1).name, ME.stack(1).line, ME.message);
                fprintf(1, '%s\n', errorMessage);
                continue
            end

        end
%         Simulation Plotting
        sim_apd = calc_apd95(t_v_sim);
        t_sim_shift = t_sim-t_sim(1);
        t_sim_scaled = t_sim_shift./sim_apd.*100;
        hold on
        % % % % % % % % % % % % % % % % % % % 
        f = plot(t_sim_scaled, sim_ion_traces(:,i), 'k', 'LineWidth', 4, 'LineSmoothing', 'on');
        
        ion_min = min(sim_ion_traces(:,i));
        ion_max = max(sim_ion_traces(:,i));
        
        if(i <= 3)
            data_peak_sim{i, cell_type} = min(sim_ion_traces(:,i));
        else
            data_peak_sim{i, cell_type} = max(sim_ion_traces(:,i));
        end
        % % % % % % % % % % % % % % % % % % % % 
        
        if ion_max > y_lim_mat(i,2)
            ylim([y_lim_mat(i,1) ion_max+0.5])
        elseif ion_min < y_lim_mat(i,1)
            ylim([ion_min-0.5, y_lim_mat(i,2)])
        else
            ylim(y_lim_mat(i,:));
        end
        
        fprintf("Avg %s In:%.2f Out:%.2f\n", peak_ion_store_names(i), avg_in, avg_out);
        fprintf("\n");



        %Display parameters

        xlim([-5 120])

        xlabel("% of APD")
        ylabel("I (A/F)")
        set(gca, 'FontSize', 50)

        title(string(cell_name)+" "+peak_ion_store_names(i), 'FontSize', 60)
        title(title_ion_store_names(i), 'FontSize', 60)
        set(gca,'linewidth',2, 'fontweight', 'bold')
        
%         print(output_root+cell_name+'_'+string(i)+'_'+peak_ion_store_names(i),'-painters', '-dsvg')

        fprintf("%s done...\n", peak_ion_store_names(i));
        close all 
        
    end 
%     fprintf("%s done...\n", cell_name);
    
end

% save("./FIGURE4_DATA/FIG4_C_EXP_IONS", 'control_exp_ions_total')
% save("./FIGURE4_DATA/FIG4_R_EXP_IONS", 'remote_exp_ions_total')
% save("./FIGURE4_DATA/FIG4_B_EXP_IONS", 'border_exp_ions_total')


toc

%% Calculate APD95 Function + Capitalize
%Will always give you the last APD present if there are multiple
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
    apd95 = t2-t1;
end

function cap_str = capitalize(in_str)
    cap_str = regexprep(in_str,'(\<[a-z])','${upper($1)}');

end

