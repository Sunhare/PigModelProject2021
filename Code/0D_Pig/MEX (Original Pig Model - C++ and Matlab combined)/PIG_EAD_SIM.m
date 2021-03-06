%% EAD Initialization
clear all;
close all;
V_EAD_FULL = [];

n_ead = 41; %Number of total data points for the EAD simulation
EAD_SIM_SWITCH = true; % Used to run EAD simulation

VIEW_IKR_RANGE = linspace(1, 0, n_ead);
IKS_RANGE = linspace(1, 0, n_ead);
CAL_RANGE = linspace(1, 4, n_ead);

IKS_SCALE = 1.00;
IKR_SCALE = 1.00;

IKR_IKS_SWITCH = 0; %0 = IKR varies w/ IKS constant, 1 = IKS varies, w/ IKR constant

%% EAD Test (CAUTION: LONG RUN TIME)
if EAD_SIM_SWITCH == true
    for cell_type = 1:3
        for IKR_IKS_SWITCH = 0:1
            if cell_type == 1 && IKR_IKS_SWITCH == 0
                continue
            end
            const_params = [5000;0;150;0.1;1;1;1;cell_type;-1];
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
            all_params = [const_params; scaling_parameters];

            tic
            if IKR_IKS_SWITCH == 0 %IKr EAD simulation
                fprintf("IKR TEST\n")

                parfor i=1:n_ead
                    for j =1:n_ead

                        CAL_SCALE = CAL_RANGE(i);
                        IKR_SCALE = VIEW_IKR_RANGE(j);
                        IKS_SCALE = 1.00;

                        PIG_EAD_SIM(cell_type, CAL_SCALE, IKR_SCALE, IKS_SCALE, all_params);
                        fprintf("IKr: %d/%d ; CaL: %d/%d\n", j,n_ead, i, n_ead);
                    end

                end

            elseif IKR_IKS_SWITCH == 1 %IKs EAD simulation
                fprintf("IKS TEST\n")
                parfor i=1:n_ead
                    for j =1:n_ead

                        CAL_SCALE = CAL_RANGE(i)
                        IKS_SCALE = IKS_RANGE(j)
                        IKR_SCALE = 1.00;

                        PIG_EAD_SIM(cell_type, CAL_SCALE, IKR_SCALE, IKS_SCALE, all_params);
                        fprintf("IKs: %d/%d ; CaL: %d/%d\n", j,n_ead, i, n_ead);
                    end
                end
            end
        end
    end
end
toc

%% Ead Load (CAUTION: LONG LOAD TIME)
% EAD_MAT = cell(n_ead*n_ead, 6);
EAD_MAT = zeros(n_ead*n_ead, 6);
EAD_PCL = 5000;


% IKS_SCALE = 1;
IKR_SCALE = 1;
% IKR_SCALE = 0.5;

cell_type = 1;

if cell_type == 1
    cell_name = "control";
elseif cell_type == 2
    cell_name = "remote";
elseif cell_type == 3
    cell_name = "border";
end

tic
for i=1:n_ead
    for j=1:n_ead

%         IKR_SCALE = IKR_RANGE(j);
        IKS_SCALE = IKS_RANGE(j);

        CAL_SCALE = CAL_RANGE(i);
        
        %Case Handling because my original way was really bad
        if cell_name == "control"
            CAL_TRUNC = ceil(CAL_SCALE*100)/100;
            
            if CAL_SCALE == 2.2 || CAL_SCALE == 0
                CAL_TRUNC = (fix(CAL_SCALE*10^2)/10^2);
            end
            IKR_TRUNC = (fix(IKR_SCALE*10^2)/10^2);
            IKS_TRUNC = (fix(IKR_SCALE*10^2)/10^2);
        
        elseif cell_name == "remote"
        end
        
        ead_identifier = "_"+sprintf("%04.2f", CAL_TRUNC)+"_"+sprintf("%04.2f", IKR_TRUNC)+"_"+sprintf("%04.2f", IKS_TRUNC)+"_";
        ead_new_name = strcat("./outputs/EAD_OLD/",strcat(cell_name,"_results_",string(5000),ead_identifier, ".txt")); 
        
        
        tic
        try
            fileID = fopen(ead_new_name,'r');
            ead_data = textscan(fileID, '%f %f %*[^\n]', 'Delimiter','\t');
            ead_data = cell2mat(ead_data);
            fprintf("Loaded %d/%d: %s\n", (i-1)*n_ead + (j-1), n_ead*n_ead, ead_new_name)
            fprintf("\n")
            fclose(fileID); 
        catch
            fprintf("ERROR, Couldn't Load: %s\n", ead_new_name)
            fprintf("ICaL Scale: %.3f, IKr Scale: %.3f, IKs Scale: %.3f\n\n", CAL_SCALE, IKR_SCALE, IKS_SCALE);
            pause(5)
        end
        toc
        
        
        t_ead = ead_data(:,1)-ead_data(1,1);
        v_ead = ead_data(:,2);
        apd1 = calc_apd95([t_ead(t_ead < EAD_PCL-1), v_ead(t_ead < EAD_PCL-1)]);
        apd2 = calc_apd95([t_ead(t_ead > EAD_PCL-1), v_ead(t_ead > EAD_PCL-1)]);
        num_eads = length(findpeaks(v_ead))/2 - 1;

        EAD_MAT(((i-1)*n_ead)+j, 1) = CAL_SCALE;
        EAD_MAT(((i-1)*n_ead)+j, 2) = IKR_SCALE;
        EAD_MAT(((i-1)*n_ead)+j, 3) = num_eads;
        EAD_MAT(((i-1)*n_ead)+j, 4) = (apd1+apd2)/2;
        EAD_MAT(((i-1)*n_ead)+j, 5) = apd1;
        EAD_MAT(((i-1)*n_ead)+j, 6) = apd2;
        



    end
end
toc

%% NEW FAST EAD PLOT
% cell_type = 2; %1 = Control, 2 = Remote, 3 = Border
% ion_sim = 3; %1 = IKR, 2 = IKS, 3 = IKS w/ 50% IKr

for cell_type = 3
    for ion_sim = 3

        if cell_type == 1
            cell_name = "CONTROL";
        elseif cell_type == 2
            cell_name = "REMOTE";
        elseif cell_type == 3
            cell_name = "BORDER";
        else
            fprintf("Error: Unknown cell type entered\n")
            return
        end

        if ion_sim == 1
            ion_name = "IKR";
        elseif ion_sim == 2
            ion_name = "IKS";
        elseif ion_sim == 3
            ion_name = "IKS_50IKR";
        else
            fprintf("Error: Unknown ion channel selected\n");
            return
        end

        ead_data = cell2mat(struct2cell(load("./outputs/EAD/"+cell_name+"_"+ion_name+"_"+"EAD.MAT")));



        figure('Position', [0 0 800 800])
        set(gcf,'Color','white'); 

        y = linspace(1,0,41)*100;
        x = linspace(1,4,41)*100;

        %This is where you choose what the z axis is plotting
        zz = reshape(max([ead_data(:,5), ead_data(:,6)]'), [length(y) length(x)]);

        [xx,yy] = meshgrid(x,y);

        colormap jet
        surf(xx,yy,zz)
        shading flat
        view(2)

        %FontSize
        set(gca, 'FontSize', 40)
        set(gca, 'FontWeight', 'bold')
        xticks(linspace(100,400,4))
        yticks(linspace(0,100,5))
%         xticks([])
%         yticks([])
        xtickformat('percentage')
        ytickformat('percentage')


        c_name = convertStringsToChars(cell_name);
         if cell_type == 1
             caxis([800 1800])
         elseif cell_type == 2
             caxis([800 2000])
         elseif cell_type == 3
             caxis([500 1600])
         end

         out_folder = "./MATLAB_FIGURE_GENERATORS/FIGURE11_EAD/";
         print(gcf, out_folder+upper(cell_name)+"_"+ion_name, '-painters', '-dsvg')
    end
end

% close all;
%% Single EAD Viewer
EAD_VIEW_CAL = 3.71;
EAD_VIEW_IKR = 0.5;
EAD_VIEW_IKS = 0.1;

EAD_VIEWER_ION_TYPE = 3;
EAD_CELL_TYPE = "border";

if EAD_VIEWER_ION_TYPE == 1
    ION_FOLDER = "IKR/";
    EAD_VIEW_IKS = 1;
elseif EAD_VIEWER_ION_TYPE == 2
    ION_FOLDER = "IKS/";
    EAD_VIEW_IKR = 1;
elseif EAD_VIEWER_ION_TYPE == 3
    ION_FOLDER = "IKS_IKR50/";
    EAD_VIEW_IKR = 0.5;
end

EAD_VIEWER(EAD_CELL_TYPE, EAD_VIEW_CAL, EAD_VIEW_IKR, EAD_VIEW_IKS)
TRACE_EAD_NAME = string(EAD_VIEW_CAL)+"_"+string(EAD_VIEW_IKR)+"_"+string(EAD_VIEW_IKS);
print(gcf, out_folder_ead_traces+upper(cell_name)+"_TRACES_EAD/"+ION_FOLDER+"TRACE_"+TRACE_EAD_NAME+".svg", '-dsvg')

%% EAD Function handler
function view_ead = EAD_VIEWER(EAD_CELL_TYPE, EAD_VIEW_CAL, EAD_VIEW_IKR, EAD_VIEW_IKS)

    EAD_PCL = 5000;
    ead_identifier_view = "_"+sprintf("%04.2f", EAD_VIEW_CAL)+"_"+sprintf("%04.2f", EAD_VIEW_IKR)+"_"+sprintf("%04.2f", EAD_VIEW_IKS)+"_";
    ead_new_name = strcat("./outputs/EAD_OLD/",strcat(EAD_CELL_TYPE,"_results_",string(EAD_PCL),ead_identifier_view, ".txt"));
    ead_view_data = load(ead_new_name);

    view_ead_t = ead_view_data(:,1)-ead_view_data(1,1);
    view_ead_v = ead_view_data(:,2);

    apd1 = calc_apd95([view_ead_t(view_ead_t<EAD_PCL), view_ead_v(view_ead_t<EAD_PCL)]);
    apd2 = calc_apd95([view_ead_t(view_ead_t>EAD_PCL), view_ead_v(view_ead_t>EAD_PCL)]);

    figure
    set(gcf, 'Renderer', 'Painters')
    set(gcf, 'PaperUnits', 'inches', 'PaperPosition', [0 0 4000 4000]/300);
%     set(gcf, 'Color', 'w')    
    

    plot(view_ead_t-EAD_PCL, view_ead_v, 'k', 'LineWidth', 40)
    box off
    set(gca,'visible','off')

    set(gca,'xtick',[])
    set(gca,'xticklabel',[])
    set(gca,'ytick',[])
    set(gca,'yticklabel',[])
    % title(sprintf("GCa: %4.2f GKr: %4.2f GKs: %4.2f", EAD_VIEW_CAL, EAD_VIEW_IKR, EAD_VIEW_IKS))
    set(gca, 'FontSize', 50)
    xlim([-100 3000])
    view_ead = 1;
    
    set(gca,'Color','none')


end

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
        
    total_error = PIG_COST_FUNCTION(ead_params, false, -1, [CAL_SCALE, KR_SCALE, KS_SCALE]); %parameters, optimization, process ID for Matlab (-2 = EAD test)
    v_ead = 1; %Dummy return variable    
end

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