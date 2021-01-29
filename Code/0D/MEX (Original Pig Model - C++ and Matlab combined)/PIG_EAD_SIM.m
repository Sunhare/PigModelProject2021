%% EAD Initialization
V_EAD_FULL = [];

%% EAD Test (CAUTION: LONG RUN TIME)
CELL_TYPE = 3;
IKR_IKS_SWITCH = 0; %0 = IKR varies w/ IKS constant, 1 = IKS varies, w/ IKR constant

if cell_type == 1
    cell_name = "control";
    all_params = control_params;
elseif cell_type == 2
    cell_name = "remote";
    all_params = remote_params;
elseif cell_type == 3
    cell_name = "border";
    all_params = border_params;
end


IKR_MAT = [0.5 1];
IKS_SCALE = 1.00;
IKR_SCALE = 1.00;

n_ead = 41; %Number of total data points for the EAD simulation
IKR_RANGE = linspace(1, 0, n);
IKS_RANGE = linspace(1, 0, n);
CAL_RANGE = linspace(1, 4, n);


tic

if IKR_IKS_SWITCH == 0 %IKr EAD simulation
    fprintf("IKR TEST\n")
    
    parfor i=1:n_ead
        for j =1:n_ead

            CAL_SCALE = CAL_RANGE(i)
            IKR_SCALE = IKR_RANGE(j)

            PIG_EAD_SIM(CELL_TYPE, CAL_SCALE, IKR_SCALE, IKS_SCALE, all_params);
            fprintf("IKs: %d/%d ; CaL: %d/%d\n", j,n_ead, i, n_ead);
        end

    end
    
elseif IKR_IKS_SWITCH == 1 %IKs EAD simulation
    fprintf("IKS TEST\n")
    parfor i=1:n_ead
        for j =1:n_ead

            CAL_SCALE = CAL_RANGE(i)
            IKS_SCALE = IKS_RANGE(j)

            PIG_EAD_SIM(CELL_TYPE, CAL_SCALE, IKR_SCALE, IKS_SCALE, all_params);
            fprintf("IKs: %d/%d ; CaL: %d/%d\n", j,n_ead, i, n_ead);
        end
    end
end

toc

%%
%TODO  fix EAD LOADING
%% Ead Load (CAUTION: LONG LOAD TIME)
EAD_MAT = cell(n_ead*n_ead, 6);
EAD_PCL = 5000;

% IKS_SCALE = 1;
IKR_SCALE = 0.5;

% border_dir = dir("outputs/results/border_results_5000*");
% border_names = border_dir.name

counter = 0;
tic
for i=1:n_ead
%     for j=1:nikr
%     for j =nikr:1
    for j=1:n_ead

%         CAL_SCALE = CAL_RANGE(i);
%         IKR_SCALE = IKR_RANGE(j);
        IKS_SCALE = IKS_RANGE(j);

        CAL_SCALE = CAL_RANGE(i);
        
        
        if CAL_SCALE == 2.20
            CAL_SCALE = 2.20;
        elseif CAL_SCALE < 2.3
            CAL_SCALE = ceil(CAL_RANGE(i)*100)/100;
        elseif CAL_SCALE > 2.3
            CAL_SCALE = ceil((CAL_RANGE(i) + 0.001)*100)/100;
        end
        
        ead_identifier = "_"+sprintf("%04.2f", CAL_SCALE)+"_"+sprintf("%04.2f", IKR_SCALE)+"_"+sprintf("%04.2f", IKS_SCALE)+"_";
        ead_new_name = strcat("./outputs/results/",strcat(cell_name,"_results_",string(5000),ead_identifier, ".txt"));
        
        tic
        try
            fileID = fopen(ead_new_name,'r');
            ead_data = textscan(fileID, '%f %f %*[^\n]', 'Delimiter','\t');
            ead_data = cell2mat(ead_data);

        catch
            fprintf("ERROR, Couldn't Load: %s\n", ead_new_name)
            fprintf("ICaL Scale: %.3f, IKr Scale: %.3f, IKs Scale: %.3f\n\n", CAL_SCALE, IKR_SCALE, IKS_SCALE);
            pause(1)
            load train.mat
            sound(y)
            return;
        end
        

        fprintf("Loaded %d/%d: %s\n", (i-1)*n_ead + (j-1), n_ead*n_ead, ead_new_name)
        toc
        fprintf("\n")
        t_ead = ead_data(:,1)-ead_data(1,1);
        v_ead = ead_data(:,2);
        apd1 = calc_apd95([t_ead(t_ead < EAD_PCL-1), v_ead(t_ead < EAD_PCL-1)]);
        apd2 = calc_apd95([t_ead(t_ead > EAD_PCL-1), v_ead(t_ead > EAD_PCL-1)]);
        num_eads = length(findpeaks(v_ead))/2 - 1;

        EAD_MAT(((i-1)*n_ead)+j, 1) = {CAL_SCALE};
        EAD_MAT(((i-1)*n_ead)+j, 2) = {IKR_SCALE};
        EAD_MAT(((i-1)*n_ead)+j, 3) = {num_eads};
        EAD_MAT(((i-1)*n_ead)+j, 4) = {(apd1+apd2)/2};
        EAD_MAT(((i-1)*n_ead)+j, 5) = {apd1};
        EAD_MAT(((i-1)*n_ead)+j, 6) = {apd2};
        fclose(fileID); 



    end
end
sound(y)
toc

%% EAD Analysis/Plot
MAT_EAD_MAT = cell2mat(EAD_MAT(:,:));

figure('Position', [0 0 1920 1080])
set(gcf,'Color','white'); 

x = CAL_RANGE;
% y = IKR_RANGE;
y = IKS_RANGE;

%This is where you choose what the z axis is plotting
zz = reshape(max([MAT_EAD_MAT(:,5), MAT_EAD_MAT(:,6)]'), [n_ead n_ead]);

[xx,yy] = meshgrid(x,y);

colormap jet
surf(xx,yy,zz)
colorbar
view(2)

xlabel("I_C_a_L")


if IKS_SCALE == 0
    ylabel("I_K_s")
else
    ylabel("I_K_r")
end

set(gca, 'FontSize', 50)
set(gca, 'FontWeight', 'bold')

if IKS_SCALE == 0 && IKR_SCALE == 1
    ylabel("I_K_s")
    print('~/Desktop/ShannonPigModel/Figures_Adobe/ead_map_cal_iks', '-painters', '-dsvg')

elseif IKS_SCALE == 0 && IKR_SCALE == 0.50
    ylabel("I_K_s ( 50% I_K_r )")
    print('~/Desktop/ShannonPigModel/Figures_Adobe/ead_map_cal_iks_050_ikr', '-painters', '-dsvg')
elseif IKR_SCALE == 0 && IKS_SCALE == 1
    ylabel("I_K_r")
    caxis([min(min(zz)) 2200])
    print('~/Desktop/ShannonPigModel/Figures_Adobe/ead_map_cal_ikr', '-painters', '-dsvg')


end



%% Single EAD Viewer
EAD_VIEW_CAL = 3.85;
EAD_VIEW_IKR = 0.05;
EAD_VIEW_IKS = 1;
EAD_PCL = 5000;
EAD_CELL_TYPE = 'control';

ead_identifier_view = "_"+sprintf("%04.2f", EAD_VIEW_CAL)+"_"+sprintf("%04.2f", EAD_VIEW_IKR)+"_"+sprintf("%04.2f", EAD_VIEW_IKS)+"_";
ead_new_name = strcat("./outputs/results/",strcat(EAD_CELL_TYPE,"_results_",string(EAD_PCL),ead_identifier_view, ".txt"));
ead_view_data = load(ead_new_name);

view_ead_t = ead_view_data(:,1)-ead_view_data(1,1);
view_ead_v = ead_view_data(:,2);

apd1 = calc_apd95([view_ead_t(view_ead_t<EAD_PCL), view_ead_v(view_ead_t<EAD_PCL)])
apd2 = calc_apd95([view_ead_t(view_ead_t>EAD_PCL), view_ead_v(view_ead_t>EAD_PCL)])

figure
set(gcf, 'Renderer', 'Painters')
set(gcf, 'Color', 'w')
plot(view_ead_t-EAD_PCL, view_ead_v, 'k', 'LineWidth', 6)
title(sprintf("GCa: %4.2f GKr: %4.2f GKs: %4.2f", EAD_VIEW_CAL, EAD_VIEW_IKR, EAD_VIEW_IKS))
set(gca, 'FontSize', 50)
% xlim([-100 1100])


%% EAD Function handler
function v_ead = PIG_EAD_SIM(cell_type, CAL_SCALE, KR_SCALE, KS_SCALE, orig_ead_params)
    n_const = 9; 
    
    ead_params = orig_ead_params;
    pcl_ead = 5000;
    ead_params(1) = pcl_ead; %PCL
    ead_params(3) = 150; %number of beats
    ead_params(5) = 1; %out_dt
    ead_params(6) = 1; %Print Last Two
    ead_params(8) = cell_type; %Cell Type

    if cell_type == 1
        cell_name = "control";
    elseif cell_type == 2
        cell_name = "remote";
    elseif cell_type == 3
        cell_name = "border";
    end

    ead_params(n_const+1) = orig_ead_params(n_const+1)*CAL_SCALE; %CaL
    ead_params(n_const+5) = orig_ead_params(n_const+5)*KR_SCALE; %IKr
    ead_params(n_const+6) = orig_ead_params(n_const+6)*KS_SCALE; %Iks
    
    fprintf("DRUG/EAD TEST\n");
    
    total_error = PIG_COST_FUNCTION(ead_params, false, -2); %parameters, optimization, process ID for Matlab (-1 = no process id)
    v_ead = 1; %Dummy return variable    
end