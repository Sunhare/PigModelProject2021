 % clear all;
% close all;

peak_ion_store_names = ["INa", "INCX", "ICa", "IK1", "IKr", "IKs", "IKCa", "ICl"];
title_ion_store_names = ["I_N_a_L", "I_N_C_X", "I_C_a", "I_K_1", "I_K_r", "I_K_s", "I_K_(_C_a_)", "I_C_l_(_C_a_)"];

tic
% y_lim for each ion channel
% y_lim_mat = [ 
%                 [-0.8 0.2];  % INa
%                 [-1.6 0.65]; % INCX
%                 [-4 0.65];   % ICa 
%                 [-0.5 3.2];  % IK1
%                 [-0.5 1.50]; % IKr
%                 [-0.1 0.5];  % IKs
%                 [-0.1 0.6];  % IKCa
%                 [-1 3.5]     % ICl
%               ];
y_lim_mat = [ 
                [-0.8 0.2];  % INa
                [-1.6 0.65]; % INCX
                [-6.1 0.65];   % ICa 
                [-0.5 3.2];  % IK1
                [-0.5 1.50]; % IKr
                [-0.1 0.5];  % IKs
                [-0.1 0.6];  % IKCa
                [-1 4.8]     % ICl
              ];

for cell_type=1:3
% for cell_type=1
    if cell_type == 1
        cell_name = "Control";
        fig4_exp_data = struct2cell(load("./FIGURE4_to_6_DATA/FIG4_C_EXP_IONS.mat"));
    elseif cell_type == 2
        cell_name = "Remote";
        fig4_exp_data = struct2cell(load("./FIGURE4_to_6_DATA/FIG4_R_EXP_IONS.mat"));
    elseif cell_type == 3
        cell_name = "Border";
        fig4_exp_data = struct2cell(load("./FIGURE4_to_6_DATA/FIG4_B_EXP_IONS.mat"));
    end
    fig4_exp_data = fig4_exp_data{1,1};
    sim_data = load("../outputs/results/"+lower(cell_name+"_results_1000.txt"));
    t_sim = sim_data(:, 1);
    v_sim = sim_data(:, 2);

    i_nal = sim_data(:,10);
    i_ncx = sim_data(:,19);
    i_cal = sim_data(:,11);
    i_k1  = sim_data(:,12);
    i_kr  = sim_data(:,13);
    i_ks  = sim_data(:,16);
    i_sk  = sim_data(:,17);
    i_cl  = sim_data(:,20);

    sim_ion_traces = [i_nal i_ncx i_cal i_k1 i_kr i_ks i_sk i_cl];

    for i = 1:8 %Loop through all ion suffixes
%     for i = 1%Loop through all ion suffixes
        figure('Position', [0 0 750 500])
        set(gcf, 'Renderer', 'Painters')
        set(gcf, 'Color', 'White')
        hold on
        for j = 1:size(fig4_exp_data,2)
            if ~isempty(fig4_exp_data{i,j})
%                 fprintf("i: %d, j: %d\n", i,j) 
                ions_tmp = fig4_exp_data{i,j};
                
                % % % % PLOT EXPERIMENTAL DATA % % % %
                plot(ions_tmp(1:30:end,1), ions_tmp(1:30:end,2), 'Color', [1 0 0 0.6]);
                % % % % PLOT EXPERIMENTAL DATA % % % %
                
            end
        end
        
        sim_apd = calc_apd95([t_sim v_sim]);
        t_sim_shift = t_sim-t_sim(1);
        t_sim_scaled = t_sim_shift./sim_apd.*100;
        hold on
        % % % % % % % % % % % % % % % % % % % 
        f = plot(t_sim_scaled, sim_ion_traces(:,i), 'k', 'LineWidth', 4);
        
        ion_min = min(sim_ion_traces(:,i));
        ion_max = max(sim_ion_traces(:,i));
      
        % % % % % % % % % % % % % % % % % % % 
        
        % if ion_max > y_lim_mat(i,2)
        %     ylim([y_lim_mat(i,1) ion_max+0.5])
        % elseif ion_min < y_lim_mat(i,1)
        %     ylim([ion_min-0.5, y_lim_mat(i,2)])
        % else
        %     ylim(y_lim_mat(i,:));
        % end
        ylim(y_lim_mat(i,:));
        curr_ylim = ylim;
        yticks([curr_ylim(1) mean(ylim) curr_ylim(2)])
        
        ytix=get(gca,'ytick')';
        set(gca,'yticklabel',num2str(ytix,'%.1f'))
        yline(0,'--')

        %PLOTTING PARAMETERES

        xlim([-5 120])

        xlabel("% of APD")
        ylabel("I (A/F)")
        set(gca, 'FontSize', 50)
        

        title(string(cell_name)+" "+peak_ion_store_names(i), 'FontSize', 60)
        title(title_ion_store_names(i), 'FontSize', 60)
        set(gca,'linewidth',2, 'fontweight', 'bold')
        set(gca, 'FontName', 'Arial')
        set(findall(gcf,'-property','FontName'),'FontName','Arial')
        
        % Print SVGs
        print('./FIGURE4_to_6_DATA/SVGs_FIG4_to_6/'+cell_name+'_'+string(i)+'_'+peak_ion_store_names(i),'-painters', '-dsvg')

    end


    close all;
end

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

