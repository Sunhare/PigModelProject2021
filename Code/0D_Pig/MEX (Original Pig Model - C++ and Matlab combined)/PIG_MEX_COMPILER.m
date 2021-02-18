%% Inputs
close all;
clear all;

% Choose cell type to simulate
cell_type = 1; %1 = Control, 2 = Remote-HF, 3 = Border-HF

%Simulation Parameters
pcl = 1000;          % Pacing Cycle Length (ms)
AP_Clamp_Switch = 0; % Run an AP Clamp simulation? 0 for false, 1 for true
nbeats = 200;        % Number of beats to simulate
dt = 0.1;            % Simulation maximumum time step (ms). Simulation uses CVODE which adapts time step 
dt_out = 0.1;		 % Output every "dt_out" time steps (if dt == dt_out, all data is kept)
output_last_two = 1; % 0 = all APs, 1 = Only keep last two in output file
hegyi_ion_data = 1;  % Ion concentrations. 0 = Original Shannon , 1 = Hegyi experimental data
s2_pcl = -1;         % S1S2 pacing protocol, S2 duration (-1 = no S1S2)

 

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
n_const = length(const_params);

if cell_type == 1
    cell_name = "control";
elseif cell_type == 2
    cell_name = "remote";
elseif cell_type == 3
    cell_name = "border";
end


%Ion channel scaling parameters
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



%% Assigning Parameters

if cell_type == 1
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/CONTROL_PARAMS_FINAL.mat"));
elseif cell_type == 2
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/REMOTE_HF_PARAMS_FINAL.mat"));
elseif cell_type == 3
    scaling_parameters = struct2array(load("./inputs/FINAL_PIG_PARAMETERS/BORDER_HF_PARAMS_FINAL.mat"));
end

param_descr_str = ["SCALE_ICa", "SCALE_INa", "SCALE_INaL", "SCALE_IK1", "SCALE_IKr", "SCALE_IKs", "SCALE_Isk", "SCALE_IClCa", "SCALE_INCX", "SCALE_INaK", "SCALE_JSRrel", "SCALE_JSERCA", "SCALE_Ito. Ito removed from model.", "SCALE_koCa, RyR Sensitivity"];

all_params = [const_params; scaling_parameters];

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

set(gcf,'color','white')
pig_data = load("./outputs/results/"+lower(cell_name)+"_results_"+string(pcl)+".txt");

t = pig_data(:,1)-pig_data(1,1);
v = pig_data(:,2);

plot(t,v,'k','LineWidth', 5)

set(gca, 'FontSize', 25)
ylabel("Voltage (mV)")
xlabel("Time (ms)")
title(CAPITALIZE(cell_name)+" Simulation PCL: "+string(pcl))

%% Parameter Store Zeroing
PARAMETER_STORE = [];

%% Full Optimization Run

% Used to optimize parameters to designated values using Nelder-Mead
% fminsearchbnd derivative free optimization

OPTIMIZATION_SWITCH = 0; 
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
%% Functions
function cap_str = CAPITALIZE(cap_var)
    if isstring(cap_var)
        str_var = convertStringsToChars(cap_var);
        cap_str = strcat(upper(str_var(1)), lower(str_var(2:end)));
    elseif ischar(cap_var)
        cap_str = strcat(upper(cap_var(1)), lower(cap_var(2:end)));
    end
end
