%% Inputs
close all;
clear all;

% Constant time parameters
cell_type = 1; %1 = Control, 2 = Remote-HF, 3 = Border-HF

pcl = 1000;          % Pacing Cycle Length (ms)
AP_Clamp_Switch = 0; % Run an AP Clamp simulation? 0 for false, 1 for true
nbeats = 200;        % Number of beats to simulate
dt = 0.1;            % Simulation maximumum time step (ms). Simulation uses CVODE which adapts time step 
dt_out = 0.1;		 % Output every "dt_out" time steps (if dt == dt_out, all data is kept)
output_last_two = 1; % 0 = all APs, 1 = Only keep last two in output file
hegyi_ion_data = 1;  % Ion concentrations. 0 = Original Shannon , 1 = Hegyi experimental data
s2_pcl = -1;         % S1S2 pacing protocol, S2 duration (-1 = no S1S2)

OPTIMIZATION_SWITCH = 0;
% Constant parameters
const_params = [
    pcl              % 1
    AP_Clamp_Switch  % 2
    nbeats           % 3
    dt               % 4
    dt_out           % 5
    output_last_two  % 6
    hegyi_ion_data   % 7
    cell_type        % 8
    s2_pcl           % 9
]; 

if cell_type == 1
    cell_name = "control";
elseif cell_type == 2
    cell_name = "remote";
elseif cell_type == 3
    cell_name = "border";
end


%Ion channel scaling parameters DEFAULT size = 13
scaling_parameters = [
    1 					% 1 SCALE_ICa
    1 					%- 2 SCALE_INa
    1 					% 3 SCALE_INaL
    1 					% 4 SCALE_IK1
    1 					% 5 SCALE_IKr
    1 					% 6 SCALE_IKs
    1 					% 7 SCALE_Isk
    1 					% 8 SCALE_IClCa
    1 					% 9 SCALE_INCX
    1 					%-10 SCALE_INaK
    1 					%-11 SCALE_JSRrel
    1 					%-12 SCALE_JSERCA
    1 					%-13 SCALE_Ito. Ito removed from model.
    1                   %14 SCALE_koCa, RyR Sensitivity
];

%% Manual parameter tuning

for CT=1:3
    n_const = length(const_params);
    if CT == 1
%         load("./outputs/OptimizedParameters/PARAMETER_STORE_control_JULY7.mat")
        load("./outputs/OptimizedParameters/PARAMETER_STORE_control_Jan292021.mat")

        scaling_params = PARAMETER_STORE(n_const+1:end,end);
        all_params = [const_params; scaling_params];
%         all_params(n_const+ 4) = 0.5;    %I_K1 scaling;
%         all_params(n_const+ 10) = 1.2; %I_NaK
%         all_params(n_const+ 14) = 5; %KoCa
        control_params = all_params;
    end

    if CT == 2
    %     load("./outputs/PARAMETER_STORE_remote_JULY20.mat")
        load("./outputs/OptimizedParameters/PARAMETER_STORE_remote_JULY30.mat")
        scaling_params = PARAMETER_STORE(n_const+1:end,end);
        all_params = [const_params; scaling_params];
        all_params(n_const + 1) = 0.8; %ICaL
        all_params(n_const + 4) = 0.55; %IK1
        all_params(n_const + 6) = 2.2; %IKs
        all_params(n_const + 7) = 8; %ISK
        all_params(n_const+ 8) = 1; %I_ClCa scaling
        all_params(n_const + 14) = 5; %koCa  
        remote_params = all_params;
    end

    if CT == 3
    %     load("./outputs/OptimizedParameters/PARAMETER_STORE_JUN5_BORDER.mat")
        load("./outputs/OptimizedParameters/PARAMETER_STORE_border_JULY14.mat")
        scaling_params = PARAMETER_STORE(n_const+1:end,end);
        all_params = [const_params; scaling_params];
        all_params(n_const + 2) = 0.8; %INa
        all_params(n_const + 3) = 2; %INaL
        all_params(n_const + 4) = 0.5; %IK1
        all_params(n_const + 5) = 1.2; %IKr
        all_params(n_const + 6) = 2; %IKs
        all_params(n_const + 8) = 0.7; %ClCa
        all_params(n_const + 14) = 5; %koCa
        border_params=all_params;

    end
end

if cell_type == 1
    all_params = control_params;
elseif cell_type == 2
    all_params = remote_params;
elseif cell_type == 3
    all_params = border_params;
end

param_descr_str = ["SCALE_ICa", "SCALE_INa", "SCALE_INaL", "SCALE_IK1", "SCALE_IKr", "SCALE_IKs", "SCALE_Isk", "SCALE_IClCa", "SCALE_INCX", "SCALE_INaK", "SCALE_JSRrel", "SCALE_JSERCA", "SCALE_Ito. Ito removed from model.", "SCALE_koCa, RyR Sensitivity"];

%Model Parameter Output
fprintf("CELL TYPE: %s\n", upper(cell_name))
for i=1:length(scaling_parameters)
    fprintf("%.2f %s\n", all_params(n_const+i), param_descr_str(i))
end
%% Compile MEX
lib_path = ['-I' fullfile(pwd,'lib')];
include_path = ['-I' '/usr/local/include'];
library_path = ['-L' '/usr/local/lib'];
sundials = ['-lsundials_cvode'];
ipaths = {[lib_path], [include_path], [library_path], [sundials]};

mex(ipaths{:}, 'PIG_MEX.cpp')

%% Single Run
tic
total_error = PIG_COST_FUNCTION(all_params); 
toc

%% Plot

pig_data = load("./outputs/results/control_results_1000.txt");

t = pig_data(:,1)-pig_data(1,1);
v = pig_data(:,2);

plot(t,v,'ok','LineWidth', 5)
% plot(pig_data(:,26),v)


%% Parameter Store Zeroing
PARAMETER_STORE = [];

%% Full Optimization Run
if OPTIMIZATION_SWITCH == 1
    tic

    lb = ones(1,14)*0.333;
    ub = ones(1,14)*4;

    scale_ical = {0.4, 1.4};
    [lb(1), ub(1)] = scale_ical{:};

    scale_ina = {0.7, 2};
    [lb(2), ub(2)] = scale_ina{:};

    scale_isk = {2, 15};
    [lb(7), ub(7)] = scale_isk{:};

    scale_iclca = {0.8, 15};
    [lb(8), ub(8)] = scale_iclca{:};

    scale_inak = {1, 1};
    [lb(10), ub(10)] = scale_inak{:};

    scale_jsr_serca = {1, 1};
    [lb(11), ub(11)] = scale_jsr_serca{:};
    [lb(12), ub(12)] = scale_jsr_serca{:};

    scale_ito = {0, 0};
    [lb(13), ub(13)] = scale_ito{:};

    scale_koCa = {0.1, 8};
    [lb(14), ub(14)] = scale_koCa{:};

    lb = [const_params' lb]';
    ub = [const_params' ub]';


    num_sims = 10;
    for i = 1:num_sims
        options = optimset('Display','iter','TolFun',1e-2, 'TolX', 1e-2, 'MaxFunEvals', 500000000, 'MaxIter', 60,'PlotFcns',@optimplotfval);
    %     options = optimset('Display','iter','TolFun',1e-2, 'TolX', 1e-2, 'MaxFunEvals', 500000000, 'MaxIter', 500); 
        parameters_new = fminsearchbnd(@PIG_COST_FUNCTION, all_params, lb, ub, options);
        all_params = parameters_new;
        PARAMETER_STORE = [PARAMETER_STORE all_params];

    end

    year_today = string(year(today('datetime')));
    month_today = string(month(today('datetime'),'shortname'));
    day_today = string(day(date));
    save(('./outputs/OptimizedParameters/PARAMETER_STORE_'+cell_name+'_'+month_today+day_today+year_today+'.mat'), 'PARAMETER_STORE');
    toc

end
