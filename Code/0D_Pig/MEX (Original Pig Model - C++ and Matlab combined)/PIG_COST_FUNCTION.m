% total_error = ss_cost_function(all_params);
function Total_Error = PIG_COST_FUNCTION(parameters, OPTIMIZATION_SWITCH, thread_ID)
    Total_Error = -1; %Initialize total error
    
    
    pcl = parameters(1);
    dt_out = parameters(5);
    
    cell_type = parameters(8);
    cell_name = [];
    if cell_type == 1
        cell_name = "control";
    elseif cell_type == 2
        cell_name = "remote";
    elseif cell_type == 3
        cell_name = "border";
    end
        
    
    if nargin<2 %Optimization can only take in 1 parameter
        OPTIMIZATION_SWITCH = true;
    end
    if nargin<3
        thread_ID=-1; 
    end
    results_file = PIG_MEX(parameters, thread_ID); %Run the simulation

%     optimization = false; %Change this if optimization is running
    
    if OPTIMIZATION_SWITCH == true
        % Load in ion channel data from text file
%         ion_sim_data = load(strcat('outputs/results/'+string(cell_name)+'_results_'+string(floor(pcl)),'.txt'));
        ion_sim_data = load(results_file);

        % AP variables
        pcln=pcl/dt_out; % integer number of PCL
        t = ion_sim_data(end-pcln+1:end,1);
        v = ion_sim_data(end-pcln+1:end,2);


        % Inward ion currents
        i_na = ion_sim_data(end-pcln+1:end,9);
        i_naL = ion_sim_data(end-pcln+1:end,10);

        i_ca = ion_sim_data(end-pcln+1:end,11);

        % Outward ion currents
        i_k1 = ion_sim_data(end-pcln+1:end,12);
        i_kr = ion_sim_data(end-pcln+1:end,13);
        i_ks = ion_sim_data(end-pcln+1:end,16);
        i_sk = ion_sim_data(end-pcln+1:end,17);

        % Exchangers

        i_nak = ion_sim_data(end-pcln+1:end,18);
        i_ncx = ion_sim_data(end-pcln+1:end,19);

        % Chloride
        i_clca = ion_sim_data(end-pcln+1:end,20);

        % Derivative
        dVdt = ion_sim_data(end-pcln+1:end,25);

        %Experimental Averages
        ion_C_exp = [
            % MIN VALUES
            -2.02 	% ICaL (A/F)
            -0.72	% INCX (A/F)
            -0.33	% INaL (A/F)

            % MAX VALUES
            2.64	% IK1 (A/F)
            1.00	% IKr (A/F)
            0.23	% IKs (A/F)
            0.23	% IK(Ca) (A/F)
            2.21	% ICl(Ca) (A/F)
        ];
    
        ion_C_exp_sem = [
            0.13 % ICaL (A/F)
            0.12 % INCX (A/F)
            0.01 % INaL (A/F)
            0.16 % IK1 (A/F)
            0.04 % IKr (A/F)
            0.02 % IKs (A/F)
            0.04 % IK(Ca) (A/F)
            0.10 % ICl(Ca) (A/F)
        ];
        ion_R_exp = [
            %MIN VALUES
            -1.79 % ICaL (A/F)
            -0.77 % INCX (A/F)
            -0.46 % INaL (A/F)
            
            %MAX VALUES
            2.59 % IK1 (A/F)
            0.88 % IKr (A/F)
            0.24 % IKs (A/F)
            0.48 % IK(Ca) (A/F)
            2.75 % ICl(Ca) (A/F)
        ];
        ion_R_exp_sem = [
            %MIN VALUES
            0.09	% ICaL (A/F)
            0.08	% INCX (A/F)
            0.03	% INaL (A/F)
            
            %MAX VALUES
            0.10	% IK1 (A/F)
            0.03	% IKr (A/F)
            0.03	% IKs (A/F)
            0.05	% IK(Ca) (A/F)
            0.18	% ICl(Ca) (A/F)
        ];
    
        ion_B_exp = [
            %MIN VALUES
            -1.40 % ICaL (A/F)
            -0.88 % INCX (A/F)
            -0.43 % INaL (A/F)

            %MAX VALUES
            2.01 % IK1 (A/F)
            0.90 % IKr (A/F)
            0.23 % IKs (A/F)
            0.46 % IK(Ca) (A/F)
            2.76 % ICl(Ca) (A/F)
        ];
        ion_B_exp_sem = [
            %MIN VALUES
            0.10 % ICaL (A/F)
            0.14 % INCX (A/F)
            0.02 % INaL (A/F)

            %MAX VALUES
            0.07 % IK1 (A/F)
            0.04 % IKr (A/F)
            0.02 % IKs (A/F)
            0.02 % IK(Ca) (A/F)
            0.12 % ICl(Ca) (A/F)
        ];
    
    
        

       
        ion_sim_vals = [i_ca i_ncx i_naL i_k1 i_kr i_ks i_sk i_clca];  

        ion_error = 0;
        curr_val = 0;
        tot_ion_error = 0;
        tot_apd_error = 0;
        ION_EXP_DATA = [];
        ION_EXP_SEM = [];
        
        if cell_type == 1
            ION_EXP_DATA = ion_C_exp;
            ION_EXP_SEM = ion_C_exp_sem;
        elseif cell_type == 2
            ION_EXP_DATA = ion_R_exp;
            ION_EXP_SEM = ion_R_exp_sem;
        elseif cell_type == 3
            ION_EXP_DATA = ion_B_exp;
            ION_EXP_SEM = ion_B_exp_sem;
        end

        %Calculate percent error squared of simulated value vs experimental
        %value
        fprintf("\n%-15s %15s %15s %15s %15s\n\n", "ION", "SIM_VAL", "EXP_VAL", "SEM", "ERROR");
        ions = ["ICaL","INCX","INaL","IK1","IKr","IKs","IK(Ca)","ICl(Ca)"];
        for i=1:size(ION_EXP_DATA,1)
            if i <= 3
                curr_val = min(ion_sim_vals(:,i));
             else
                curr_val = max(ion_sim_vals(:,i));
            end
               
            if curr_val <= ION_EXP_DATA(i) + ION_EXP_SEM(i) && curr_val >= ION_EXP_DATA(i) - ION_EXP_SEM(i)
                ion_error = 0;
            else
                ion_error_1 = (1 - curr_val/(ION_EXP_DATA(i)+ion_C_exp_sem(i)))^2; %Percent Error
                ion_error_2 = (1 - curr_val/(ION_EXP_DATA(i)-ion_C_exp_sem(i)))^2; %Percent Error
                ion_error = min(ion_error_1, ion_error_2);
            end

            tot_ion_error = tot_ion_error + ion_error;
            fprintf("%-15s %15.3f %15.2f %15.2f %15.3f\n", ions(i), curr_val, ION_EXP_DATA(i), ION_EXP_SEM(i), ion_error);
        end
        fprintf("TOT.ION.ERR: %10.6f\n\n ", tot_ion_error );
        fprintf("\n");

        %APD error
        
             %Load APD information
            apd_sim_data = load(strcat('outputs/APDs/',string(cell_name),'_APD_'+string(floor(pcl)),'.txt'));

        %   APD_count	 				= apd_sim_data(end,  1);
            APD95  						= apd_sim_data(end,  2);
            APD50  						= apd_sim_data(end,  3);
            Vmax 						= apd_sim_data(end,  4);
            Vmin                    	= apd_sim_data(end,  5);
            dVdtmax 					= apd_sim_data(end,  6);
            neg_dVdtmax  				= apd_sim_data(end,  7);
            plateau50 					= apd_sim_data(end,  8);
            plateau75 					= apd_sim_data(end,  9);
            CaT_max  					= apd_sim_data(end, 10);
            CaT_min   					= apd_sim_data(end, 11);
            CaD_Tau 			 		= apd_sim_data(end, 12);
            CaD_peak_T 					= apd_sim_data(end, 13);
            INa_max 					= apd_sim_data(end, 14);
            CaSR_peak 					= apd_sim_data(end, 15);
            CaSR_min  					= apd_sim_data(end, 16);

            
            %Physiological Limits
%             phys_goal = [
%                 CaT_max = 0.5
%             ]
            %Experimental values
            apd_control_expected = [
                244.19737 % APD95 at 1 HZ 
                1.31941 % Triangulation (APD95/APD50)
                62.64842  % V max 
                -82.89167 % V rest
                332.20077 % dvdt Max
                -2.21     % -dvdt max
                18.63474  % Plateau50 at 1 HZ
                -5.11789  % Plateau75
                0.5       % CaT_peak goal (mM)
                0.1       % CaT_min  goal (mM)
                200       % CaD_tau  goal (ms)
                7.1105    % (%) of APD Peak of CaT occurs
                %No EXP Data (modeler choice)
                -330       % INa (similar to dVdt)
                1.2      % [SR]max goal (mM)
                0.5      % [SR]min goal (mM)
                
                
                
            ];
            
             apd_control_sem = [
                7.46484 % APD95 at 1 HZ
                0.02281 % Triangulation 
                1.15246  % V max 
                0.54111  % V rest
                9.08241  %dvdt Max
                0.06818  %-dvdt Max
                0.90522  % Plateau50 at 1 HZ
                1.10374  % Plateau75
                0.0      % CaT_peak goal (mM)
                0.0      % CaT_min  goal (mM)
                0.0      % CaD_tau  goal (ms)
                2.9540   % (%) of APD Peak of CaT occurs
                20.0      % INa (similar to dVdt)
                0.2      % [SR]max goal (mM)
                0.2      % [SR]min goal (mM)
            ];
        
            apd_remote_expected = [
                284.04654 % APD95 at 1 HZ 
                1.33888 % Triangulation (APD95/APD50)
                61.29923 % V max 
                -82.79154 % V rest
                312.4 % dvdt Max
                -2.03692 % -dvdt max
                19.52231 % Plateau50 at 1 HZ
                -5.12769 % Plateau75
                0.5       % CaT_peak goal (mM)
                0.1       % CaT_min  goal (mM)
                200       % CaD_tau  goal (ms)
                7.38    % (%) of APD Peak of CaT occurs
                %No EXP Data (modeler choice)
                -312       % INa (similar to dVdt)
                1.2      % [SR]max goal (mM)
                0.5      % [SR]min goal (mM)
                

            ];

            apd_remote_expected_sem = [
                11.76227 % APD95 at 1 HZ 
                0.01301 % Triangulation (APD95/APD50)
                1.33237 % V max 
                0.56967 % V rest
                7.5     % dvdt Max
                0.04739 % -dvdt max
                0.80405 % Plateau50 at 1 HZ
                0.93281 % Plateau75
                0.3      % CaT_peak goal (mM)
                0.3      % CaT_min  goal (mM)
                50.0      % CaD_tau  goal (ms)
                1.83   % (%) of APD Peak of CaT occurs
                20.0      % INa (similar to dVdt)
                0.3      % [SR]max goal (mM)
                0.3      % [SR]min goal (mM)
            ];
        
            apd_border_expected = [
                209.86696	% APD95 at 1 HZ 
                1.4347		% Triangulation (APD95/APD50)
                58.28217	% V max 
                -81.30609	% V rest
                286.39696	% dvdt Max
                -1.80696	% -dvdt max
                14.40261	% Plateau50 at 1 HZ
                -13.58913	% Plateau75
                0.5       % CaT_peak goal (mM)
                0.1       % CaT_min  goal (mM)
                200       % CaD_tau  goal (ms)
                10.017    % (%) of APD Peak of CaT occurs
                %No EXP Data (modeler choice)
                -286       % INa (similar to dVdt)
                1.2      % [SR]max goal (mM)
                0.5      % [SR]min goal (mM)
                
            ];

            apd_border_expected_sem = [
                5.14108 % APD95 at 1 HZ 
                0.02543 % Triangulation (APD95/APD50)
                0.98751 % V max 
                0.55439 % V rest
                13.77204 % dvdt Max
                0.04988 % -dvdt max
                0.95386 % Plateau50 at 1 HZ
                1.08967 % Plateau75
                0.3       % CaT_peak goal (mM)
                0.3       % CaT_min  goal (mM)
                50       % CaD_tau  goal (ms)
                3.29    % (%) of APD Peak of CaT occurs
                %No EXP Data (modeler choice)
                -312       % INa (similar to dVdt)
                0.3      % [SR]max goal (mM)
                0.3      % [SR]min goal (mM)
            ];
        
        
            APD_EXP_DATA = [];
            APD_EXP_SEM = [];
            
            if cell_type == 1
                APD_EXP_DATA = apd_control_expected;
                APD_EXP_SEM = apd_control_sem;
            elseif cell_type == 2
                APD_EXP_DATA = apd_remote_expected;
                APD_EXP_SEM = apd_remote_expected_sem;
            elseif cell_type == 3
                APD_EXP_DATA = apd_border_expected;
                APD_EXP_SEM = apd_border_expected_sem;
            end
%             apd_sim_vals = apd_sim_data(end, 2:9);
            apd_sim_vals = apd_sim_data(end, 2:16);
            apd_sim_vals(2) = apd_sim_vals(1)/apd_sim_vals(2); %Triangulation value
            apds = ["APD95","Triangulation","Vmax","Vmin","dVdtmax","-dVdtmax","plat50","plat75", "CaT_max", "CaT_min", "CaD_tau", "CaT_peak_t (%)", "INa_max", "SR_max", "SR_min"];
            apd_error = 0;
            curr_val = 0;

            %Calculate APD error
            weight_matrix_apd = ones(length(apd_sim_vals), 1);
            weight_matrix_apd(1) = 200; %APD weight = 20
            weight_matrix_apd(12) = 10; %APD weight = 20
            
            fprintf("\n%-15s %15s %15s %15s %15s\n\n", "NAME", "SIM_VAL", "EXP_VAL", "SEM", "ERROR");
            for i=1:(size(apd_control_expected,1))
                curr_val = apd_sim_vals(end, i);
                if i==12
                    curr_val = curr_val/apd_sim_vals(end, 1)*100; %Divide CaT Peak time by APD for percent
                elseif i==9 || i==10
                    curr_val = curr_val*1000; %Converting to µM
                end
%                 curr_apd_error = ((1 - apd_control_expected(i)/curr_val)^2)*weight_matrix_apd(i);
                
                if curr_val <= APD_EXP_DATA(i) + APD_EXP_SEM(i) && curr_val >= APD_EXP_DATA(i) - APD_EXP_SEM(i)
                    apd_error = 0;
                else
                    apd_error_1 = weight_matrix_apd(i)*(1 - curr_val/(APD_EXP_DATA(i)+APD_EXP_SEM(i)))^2; %Percent Error
                    apd_error_2 = weight_matrix_apd(i)*(1 - curr_val/(APD_EXP_DATA(i)-APD_EXP_SEM(i)))^2; %Percent Error
                    apd_error = min(apd_error_1, apd_error_2);

                end
                
        %         fprintf("\n%5d \t %10.6f \t %10.6f \t %10.6f\n", i, curr_val, apd_control_expected(i), apd_error);
            tot_apd_error = tot_apd_error + apd_error; %Percent Error     
            fprintf("%-15s %15.3f %15.2f %15.2f %15.3f\n", apds(i), curr_val, APD_EXP_DATA(i), APD_EXP_SEM(i), apd_error);
            end
            fprintf("TOT.APD.ERR: %10.6f\n\n ", tot_apd_error );
        



        Total_Error = tot_ion_error + tot_apd_error;
        fprintf("TOT.ERR: %10.6f\n\n ", Total_Error );
    end


end