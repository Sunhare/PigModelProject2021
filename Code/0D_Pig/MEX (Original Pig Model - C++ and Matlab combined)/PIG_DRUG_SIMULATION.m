%% "Drug" Simulation

close all;
test_params = zeros(length(all_params));

scale_names = ["ICa","INa","INaL","IK1","IKr","IKs","Isk","IClCa","INCX","INaK","JSR","JSERCA","Ito","koCa"];
test_color = [
    [1 0 0];
    [0 1 0 ];
    [0 0 1];
    ];
for param_to_test = [1 4 5]
% for param_to_test = 1
    counter = 1;
    
%     test_params = all_params;
    scales_list = [0.3 0.5 1 1.5 2];
    n_scales = length(scales_list);
    
    for i = 1:n_scales
        figure
        set(gcf, 'Color', 'White')
        hold on
        test_params = all_params;
        test_scale = scales_list(i);
        
        test_params(n_const+param_to_test) = test_params(n_const+param_to_test)*test_scale;
        tic
        fprintf("Changing %s from %.2f to %.2f\n", scale_names(param_to_test), all_params(n_const+param_to_test), test_params(n_const+param_to_test))
        total_error = PIG_COST_FUNCTION(test_params, false, -1); %parameters, optimization, process ID for Matlab (-1 = no process id)
        toc
        path = strcat("/Users/satolab/Desktop/ShannonPigModel/Cpp_files/outputs/results/",cell_name,"_results_");
        test_data = load(strcat(path, string(1000),".txt"));
        
        t = test_data(:,1)-test_data(1);
        v = test_data(:,2);
%         subplot(n_scales, 1, i);
        plot(t,v, 'k', 'LineWidth', 2)
        t_str = upper(cell_name) + " " + scale_names(param_to_test) + "*=" + string(test_scale);
        ylabel("V_m (mV)")

        xlabel("Time (ms)")
        
        xlim([850 1300]);
        ylim([-100 100]);
        set(gca, 'FontSize', 25)
        title((t_str));
        set(gca, 'FontWeight', 'Bold')
        
        out_drug_path = "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/outputs/drug_sims/";

        f_str =sprintf("%s_%s_%.1f", upper(cell_name), scale_names(param_to_test), test_scale);
        daspect([1 1.5 1])
        print(out_drug_path+f_str+".png",'-dpng')
        close all
        
    end
    counter = counter + 1
end 
% tic
% total_error = PIG_COST_FUNCTION(test_params, true, -1); %parameters, optimization, process ID for Matlab (-1 = no process id)
% toc
