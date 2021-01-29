% Load Exp Data (Fast)


%Since the experimental data isn't all the same length, we store it in a
%cell object
clear;
close all;

%%

for cell_type =1:3
    if cell_type == 1
        load('figure1_data/c_ions_data.mat')
        data_ions_tmp = c_ions_data;
        ap_data = load("figure1_data/control_results_1000.txt");
        cell_name = "Control";
    elseif cell_type == 2
        load('figure1_data/r_ions_data.mat')
        data_ions_tmp = r_ions_data;
        ap_data = load("figure1_data/remote_results_1000.txt");
        cell_name = "Remote";
    elseif cell_type == 3
        load('figure1_data/b_ions_data.mat')
        data_ions_tmp = b_ions_data;
        ap_data = load("figure1_data/border_results_1000.txt");
        cell_name = "Border";
    else
        fprintf("Error: Unrecognized Cell Type: %d\n", cell_type)
        return;
    end
    fprintf("Cell Type: %s\n", cell_name);
    
    % Process Experimental Data/Output (Step 2 AP Traces, Large File Size)
    out_t = 0:0.02:318.98;
    out_apd = [out_t'];
    out_apd = {};

    counter = 1;
    for j=1:length(data_ions_tmp)

        if(cell_type == 1 && (j == 8 || j == 15)) %Processing data
            continue
        elseif(cell_type == 2 && (j == 4 || j == 27  || j == 6))
            continue
        elseif(cell_type == 3 && (j == 4 || j == 7 || j == 22))
            continue
        end

        tmp_data = data_ions_tmp{1,j};
        t = table2array(tmp_data(:,1));
        v = table2array(tmp_data(:,2:end))-6;

        for i=1:size(v,2)
            tmp_v = v(:,i);     
            if mod(i,1)==0
                out_apd = [out_apd tmp_v(1:length(out_t))];
                out_apd(1, counter) = {tmp_v(1:1:end)};
                counter = counter +1;
            end
        end
    end


    % % % % % % % Compress AP Traces % % % % % % %
    
    %Manuscript Output  (Step 3 AP Traces, Compress File Sizes)
    skip_factor = 3; %How many total EXP traces to skip (number of AP compression)
    compress_factor = 30; %How many individual data points to skip (time compression)

    fprintf("Total experimental compression: %dx\n", skip_factor*compress_factor);

    figure('Position',[0 0 1920 1080])
    set(gcf, 'Renderer', 'Painters')
    set(gcf, 'Color', 'white')


    compressed_apd = out_apd(1:skip_factor:end);
    hold on

    for i =1:length(compressed_apd)
        mat_comp_apd = cell2mat(compressed_apd(i));
        exp_ap_dt = 0.02;
        s = length(cell2mat(compressed_apd(i))); %Get the length of the AP matrix
        t_compressed = 0:exp_ap_dt:((s-1)*exp_ap_dt); %Make "psuedo" time vector
        lh = plot(t_compressed(1:compress_factor:end), mat_comp_apd(1:compress_factor:end)); %Plot them
        
        % % % Experimental Plotting % % %
        lh.Color = [1,0,0,0.15]; %Control compressed experimental color
    end

    t_sim = ap_data(1:end/2,1)-ap_data(1,1)+9.64; %+9.64 to match experimental stimulation
    v_sim = ap_data(1:end/2,2);

    % % % % % % PLOTTING OPTIONS % % % % % %

    plot(t_sim,v_sim, 'k', 'LineWidth', 10) % % % Plot simulation line % % %
    xlim([0 400])
    ylim([-100 100])
    set(gca, 'FontSize', 70)
    xlabel("t (ms)",'FontSize', 80, 'fontweight', 'normal');
    ylabel("V (mV)",'FontSize', 80, 'fontweight', 'normal');

    title(capitalize(cell_name)+" AP", 'FontSize', 120);
    L(1) = plot(nan, nan, 'r-', 'LineWidth', 10);
    L(2) = plot(nan, nan, 'k-', 'LineWidth', 10);
    legend(L, {'Exp', 'Model'}, 'fontweight', 'normal', 'FontSize', 70)
    set(legend,'Location', 'NorthEast')
    legend boxoff
    set(gca, 'FontName', 'Arial')

    output_root = 'figure_1/';
    print(output_root+cell_name+'_'+'AP_traces','-painters', '-dsvg')
%%  % % % % % % % % DATA ANALYSIS % % % % % % % % 
    
    curr_apd = calc_apd95([t_sim v_sim]);
    curr_vmax = max(v_sim);
    curr_vmin = min(v_sim);
    
 
    fprintf("%s Cell Analysis\n", cell_name)
    fprintf("APD: %.2f\n", curr_apd);
    fprintf("Vmax: %.2f\n", curr_vmax);
    fprintf("Vmin: %.2f\n\n", curr_vmin);
    
    
    
    
end

%% Calculate APD95 and Capitalize Function
function apd95 = calc_apd95(t_v)

    t = t_v(:,1);
    v = t_v(:,2);
    
    n = length(t);
    
    max_v = max(v);
    min_v = min(v);
    amp = max_v - min_v;
    v95 = max_v - (0.95*amp);
    
    t1 = 0;
    t2 = 0;
    t1_bool = false;
    t2_bool = false;
    
    for i = 2:n 
        if(t(i) > 5 && v(i) > v95 && v(i-1) < v95 && t1_bool == false)
            t1 = t_v(i,1);
            t1_bool = true;
        end
        if(t(i) > 15 && v(i) < v95 && v(i-1) > v95 && t2_bool == false)
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
%         fprintf("Error: Strange Case found in APD95 calculation")
        error("Error: Strange Case found in APD95 calculation")
    end
    
    if t1 > t2
%         fprintf("Error: Negative APD (t1: %.2f, t2: %.2f)\n", t1, t2)
        error("Error: Negative APD (t1: %.2f, t2: %.2f)\n", t1, t2)
    end
end

function cap_str = capitalize(in_str)
    cap_str = regexprep(in_str,'(\<[a-z])','${upper($1)}');

end