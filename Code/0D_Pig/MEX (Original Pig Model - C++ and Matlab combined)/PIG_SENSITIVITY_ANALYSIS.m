%% Initialize X and Y for SA
X=[]; %Store parameters
Y=[]; %Store biomarkers
X_control = [];
Y_control = [];
X_remote = [];
Y_remote = [];
X_border = [];
Y_border = [];
%% Sensitivity Analysis (Generate X and Y, Computationally Expensive)

for cell_type=1:3

n = 500;

tic
n_x = length(scaling_parameters);
n_y = 15;

X_control = zeros(n,n_x);
X_remote = zeros(n,n_x);
X_border = zeros(n,n_x);
X=zeros(n,n_x);
Y_control = zeros(n,n_y);
Y_remote = zeros(n,n_y);
Y_border = zeros(n,n_y);
Y=zeros(n,n_y);

parfor i=1:n
    pid = feature('getpid')
    fprintf("\n ITERATION: %d OF %d, PID: %d\n ", i, n, pid);
    
    all_params = zeros(length(control_params),1);
    
    if cell_type == 1
        all_params = control_params; 
    elseif cell_type == 2
        all_params = remote_params;
    elseif cell_type == 3
        all_params = border_params;
    end


    p = length(scaling_parameters);
    x1 = lognrnd(0, 0.15, 1, p);
    fprintf("Generating random numbers...\n")
    all_params(n_const+1:end) = all_params(n_const+1:end).*x1'; %Scale parameters log normally
    
    
    fprintf("Running simulation...\n")
    total_error = PIG_COST_FUNCTION(all_params, false, pid);
    
    %Load APD information
    apd_sim_data = load(strcat('outputs/APDs/',string(cell_name),'_APD_'+string(floor(pcl)),'_', string(pid),'.txt'));

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
    y1 = [APD95,APD50,Vmax,Vmin,dVdtmax,neg_dVdtmax,plateau50,plateau75,CaT_max,CaT_min,CaD_Tau,CaD_peak_T,INa_max,CaSR_peak,CaSR_min];
%     if cell_type == 1
%         X_control = [X_control; x1];
%         Y_control = [Y_control; y1];
%     elseif cell_type == 2
%         X_remote = [X_remote; x1];
%         Y_remote = [Y_remote; y1];
%     elseif cell_type == 3
%         X_border = [X_border; x1];
%         Y_border = [Y_border; y1];
%     end
%     X=[X;x1];
%     Y=[Y;y1];
    if cell_type == 1
        X_control(i,:) = x1;
        Y_control(i,:) = y1;
    elseif cell_type == 2
        X_remote(i,:) = x1;
        Y_remote(i,:) = y1;
    elseif cell_type == 3
        X_border(i,:) = x1;
        Y_border(i,:) = y1;
    end
    X(i,:) = x1;
    Y(i,:) = y1;
        
end

if cell_type == 1
    save("./outputs/SA/X_control.txt", 'X_control', '-ascii','-tabs')
    save("./outputs/SA/Y_control.txt", 'Y_control', '-ascii','-tabs')
elseif cell_type == 2
    save("./outputs/SA/X_remote.txt", 'X_remote', '-ascii','-tabs')
    save("./outputs/SA/Y_remote.txt", 'Y_remote', '-ascii','-tabs')
elseif cell_type == 3
    save("./outputs/SA/X_border.txt", 'X_border', '-ascii','-tabs')
    save("./outputs/SA/Y_border.txt", 'Y_border', '-ascii','-tabs')
end
toc
end



%% SA Distribution View and Normalization 
X_control = load('./outputs/SA/X_control.txt');
Y_control = load('./outputs/SA/Y_control.txt');
X_remote = load('./outputs/SA/X_remote.txt');
Y_remote = load('./outputs/SA/Y_remote.txt');
X_border = load('./outputs/SA/Original_Run/X_border.txt');
Y_border = load('./outputs/SA/Original_Run/Y_border.txt');

cell_name = "Border";

y_names = ["APD95","APD50","Vmax","Vmin","dVdtmax","neg_dVdtmax","plateau50","plateau75","CaT_max","CaT_min","CaD_Tau","CaD_peak_T","INa_max","CaSR_peak","CaSR_min"];

y_probs = zeros(size(Y,2),1);
for i =1:size(Y,2)
% for i =1
    
    tmp = Y(:,i);
    [h,p] = lillietest(tmp, 'Alpha', 0.1);
    y_probs(i) = h;
    
    contains_neg = any(Y(:,i)<0);
    
    
    if h==1
        fprintf("%12s NOT NORMAL (i: %d, p=%06.3f)", y_names(i),i, p)
        if contains_neg == 1
            y_probs(i) = 0;
            fprintf(" Negatives in %s", y_names(i))
        end
        fprintf("\n")
    end
    
end

X_log = log(X);

Y_log = Y;
y_probs([4,7,8])= 0; %Fixing values that have negatives in them, messes up log transform
Y_log(:,y_probs==1) = log(Y(:,y_probs==1)); %Log Transform non-normal values

X_z = zscore(X_log); %Convert to Z-score
Y_z = zscore(Y_log);



%% Perform PLS Sensitivty Analysis

[T,P,W,Wstar,U,b,C,B_pls,...
Bpls_star,Xori_rec,Yori_rec,...
R2_X,R2_Y]=PLS_nipals(X_z,Y_z);

%% Heat Map SA
n_iters=length(Xori_rec)
set(gcf,'Color', 'white')
cmap = [
  [linspace(0,1,128)'; linspace(1,1,128)'],[linspace(0,1,128)'; linspace(1,0,128)'], [linspace(1,1,128)'; linspace(1,0,128)']
    
];

x_indices = [1:10, 14];
y_indices = [1:6, 9:15];
B_pls_filtered = B_pls(x_indices, y_indices);
h = heatmap(B_pls_filtered', 'Colormap', cmap);
h.Title = sprintf("%s Cell Sensitivity Analysis at %d Hz (n=%d)", capitalize(cell_name), 1/(pcl/1000), n_iters);
h.XData = {'ICa','INa','INaL','IK1','IKr','IKs','Isk','IClCa','INCX','INaK','koCa'};
h.YData = {'APD95','APD50','Vmax','Vmin','dVdt_m_a_x','-dVdtmax','CaT_m_a_x','CaT_m_i_n','CaD_T_a_u','CaD_p_e_a_k _T','INa_m_a_x','CaSR_p_e_a_k', 'CaSR_m_i_n'};
h.CellLabelFormat = '%.2f';
set(gca, 'FontSize', 25)

%%

fprintf("%s Cell Sensitivity Analysis at %d Hz (n=%d)\n", capitalize(cell_name), 1/(pcl/1000), n_iters)
%% Calculate R2 for Sensitivity Analysis

Y_pred = X_z*B_pls;

num_y = size(Y_pred,2);

y_r2 = zeros(num_y,1);

for i = 1:num_y
    z_apd_true = Y_z(:,i);
    z_apd_pred = Y_pred(:,i);

    mdl = fitlm(z_apd_true,z_apd_pred);
    y_r2(i) = mdl.Rsquared.Adjusted

end

figure
set(gcf,'Color', 'white')
y_cat_names = categorical(y_names);
y_cat_names = reordercats(y_cat_names, ["APD95","APD50","Vmax","Vmin","dVdtmax","neg_dVdtmax","plateau50","plateau75","CaT_max","CaT_min","CaD_Tau","CaD_peak_T","INa_max","CaSR_peak","CaSR_min"]);
% y_cat_names = reordercats(y_cat_names, 
bar(y_cat_names,y_r2)
set(gca, 'FontSize', 50)
ylim([0.5 1])

function cap_str = capitalize(in_str)
    cap_str = regexprep(in_str,'(\<[a-z])','${upper($1)}');

end