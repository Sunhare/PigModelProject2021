%% Pacing Frequency Run

cell_type = 1; %0 = Control, 1 = Remote-HF, 2 = Border-HF

pcl_array = [200, 250, 333.3, 500, 1000, 2000, 5000];
exp_apd_C = [125.2, 142.5, 165.9, 201.5, 244.2, 282.3, 307.46]; %Expected mean experimental APDs
exp_apd_sem_C = [3.77, 3.72, 5.93, 7.34, 7.46, 11.97, 15.13]; %Expected SEM experimental APDs

exp_apd_R = flip([376.96111,335.09294,284.04654,242.50684,193.332,165.31533,143.84333]); %Expected mean experimental APDs
exp_apd_sem_R = flip([24.8892,20.51169,11.76227,9.80325,6.17328,4.36233,3.09966]); %Expected SEM experimental APDs

exp_apd_B = flip([255.57923,229.12667,209.86696,176.51308,150.40846,131.55083,116.22182]); %Expected mean experimental APDs
exp_apd_sem_B = flip([6.56633,6.62278,5.14108,4.93677,4.07413,3.91533,3.02591]); %Expected SEM experimental APDs

if cell_type == 1
    exp_apd = exp_apd_C;
    exp_apd_sem = exp_apd_sem_C;
elseif cell_type == 2
    exp_apd = exp_apd_R;
    exp_apd_sem = exp_apd_sem_R;
elseif cell_type == 3
    exp_apd = exp_apd_B;
    exp_apd_sem = exp_apd_sem_B;
end

apd_array = [];
apd_2nd_last = [];
tic
for i=1:length(pcl_array)
    all_params(1)=pcl_array(i);
    
    total_error = PIG_COST_FUNCTION(all_params, false, -1);
    
    apd_sim_data = load(strcat('outputs/APDs/',string(cell_name),'_APD_'+string(floor(pcl_array(i))),'.txt'));
    APD95 = apd_sim_data(end,  2);
    APD95_2 = apd_sim_data(end-1,  2);
    
    apd_array = [apd_array APD95];
    apd_2nd_last = [apd_2nd_last APD95_2];
end
toc
 
%% Plot Pacing Frequency
% openfig('exp_rate_dependency.fig');
% openfig('exp_rate_dependency_remote.fig');
% hold on
set(gcf, 'Color', 'white')
f = 1./(pcl_array./1000); % frequencies
plot(f, apd_2nd_last, 'Xm',  'MarkerSize', 60, 'LineWidth', 5)
plot(f, apd_array, 'Xk',  'MarkerSize',60, 'LineWidth', 5)


errorbar(f,exp_apd,exp_apd_sem, 'o', 'Color', 'b', 'LineWidth', 2)

xlabel("Frequency (Hz)")
ylabel("APD_9_5 (ms)")
title(strcat(capitalize(cell_name)," Cell Pacing Relationship"))
% legend("APD_n ", "APD_n_-_1");
set(gca, 'FontSize', 50)

rss = sum(((apd_array-exp_apd)./exp_apd).^2)*100;
text(0.25, 100, strcat("RSS: ",string(rss)), 'FontSize', 30)

%% Initialize Arrays Bifurcation Simulation
control_rd_all = [];
remote_rd_all = [];
border_rd_all = [];

%% Bifurcation Simulation
apd_array_bifurc = [];
apd_2nd_last_bifurc = [];

apd90_array_bifurc = [];
apd90_2nd_last_bifurc = [];

apd75_array_bifurc = [];
apd75_2nd_last_bifurc = [];

di_array_bifurc = [];
di_array_2nd_bifurc = [];

cat_max_bifurc = [];
cat_min_bifurc = [];

cat_2nd_max_bifurc = [];
cat_2nd_min_bifurc = [];

nai_max_bifurc = [];
nai_2nd_max_bifurc = [];

pcl_bifurc_array = [100:10:300 300:50:2000];
% cell_type = 2;

if cell_type == 1
    cell_name = "control";
elseif cell_type == 2
    cell_name = "remote";
elseif cell_type == 3
    cell_name = "border";
end

tic
for i=1:length(pcl_bifurc_array)
    pcl_bifurc = pcl_bifurc_array(i);
    all_params(1)=pcl_bifurc;
    all_params(8)=cell_type;

    total_error = PIG_COST_FUNCTION(all_params, false, -1);

    apd_sim_data = load('/Users/satolab/Desktop/ShannonPigModel/Cpp_files/outputs/APDs/'+string(cell_name)+'_APD_'+string(floor(pcl_bifurc))+'.txt');
    ion_sim_data = load('/Users/satolab/Desktop/ShannonPigModel/Cpp_files/outputs/results/'+string(cell_name)+'_results_'+string(floor(pcl_bifurc))+'.txt');

    APD95 = apd_sim_data(end,  2);
    APD95_2 = apd_sim_data(end-1,  2);
    
    APD90 = apd_sim_data(end, 17);
    APD90_2 = apd_sim_data(end-1, 17);
    
    APD75 = apd_sim_data(end, 18);
    APD75_2 = apd_sim_data(end-1, 18);
    
    CaT_Peak = apd_sim_data(end,  10);
    CaT_Peak_2 = apd_sim_data(end-1,  10);

    CaT_Diast = apd_sim_data(end, 11);
    CaT_Diast_2 = apd_sim_data(end-1,  11);

    apd_array_bifurc = [apd_array_bifurc APD95];
    apd_2nd_last_bifurc = [apd_2nd_last_bifurc APD95_2];
    
    apd90_array_bifurc = [apd90_array_bifurc APD90];
    apd90_2nd_last_bifurc = [apd90_2nd_last_bifurc APD90_2];
    
    apd75_array_bifurc = [apd75_array_bifurc APD75];
    apd75_2nd_last_bifurc = [apd75_2nd_last_bifurc APD75_2];
    
    di_array_bifurc = [di_array_bifurc pcl_bifurc-APD95];
    di_array_2nd_bifurc = [di_array_2nd_bifurc pcl_bifurc-APD95_2];

    cat_max_bifurc = [cat_max_bifurc CaT_Peak];
    cat_min_bifurc = [cat_min_bifurc CaT_Diast];

    cat_2nd_max_bifurc = [cat_2nd_max_bifurc CaT_Peak_2];
    cat_2nd_min_bifurc = [cat_2nd_min_bifurc CaT_Diast_2];

    Nai_Max = max(ion_sim_data( (end-pcl_bifurc/dt_out):end, 4));
    Nai_2nd_Max = max(ion_sim_data((end-(2*pcl_bifurc)/dt_out)+1:(end-(pcl_bifurc/dt_out)),4));

    nai_max_bifurc = [nai_max_bifurc Nai_Max];
    nai_2nd_max_bifurc = [nai_2nd_max_bifurc Nai_2nd_Max];

end
toc
% Prism Output APD vs PCL

if cell_type == 1
    disp("Saved Control")
    control_rd_all = [pcl_bifurc_array; apd_array_bifurc; apd_2nd_last_bifurc; di_array_bifurc; di_array_2nd_bifurc; cat_max_bifurc; cat_min_bifurc; cat_2nd_max_bifurc; cat_2nd_min_bifurc; nai_max_bifurc; nai_2nd_max_bifurc]';
    save("/Users/satolab/Desktop/ShannonPigModel/Cpp_files/Prism_Data/control_rd_all.txt", 'control_rd_all', '-ascii','-tabs')
elseif cell_type == 2
    remote_rd_all = [pcl_bifurc_array; apd_array_bifurc; apd_2nd_last_bifurc; di_array_bifurc; di_array_2nd_bifurc; cat_max_bifurc; cat_min_bifurc; cat_2nd_max_bifurc; cat_2nd_min_bifurc; nai_max_bifurc; nai_2nd_max_bifurc]';
    save("/Users/satolab/Desktop/ShannonPigModel/Cpp_files/Prism_Data/remote_rd_all.txt", 'remote_rd_all', '-ascii','-tabs')
elseif cell_type == 3
    border_rd_all = [pcl_bifurc_array; apd_array_bifurc; apd_2nd_last_bifurc; di_array_bifurc; di_array_2nd_bifurc; cat_max_bifurc; cat_min_bifurc; cat_2nd_max_bifurc; cat_2nd_min_bifurc; nai_max_bifurc; nai_2nd_max_bifurc]';
    save("/Users/satolab/Desktop/ShannonPigModel/Cpp_files/Prism_Data/border_rd_all.txt", 'border_rd_all', '-ascii','-tabs')
end
   

%% Plot Bifurcation
figure(1)
set(gcf, 'Color', 'white')
hold on

skip_two_one = 1; %Skip 2 to 1 response where not repolarized enough

plot(pcl_bifurc_array(skip_two_one:end), apd_2nd_last_bifurc(skip_two_one:end), 'ob', 'MarkerFaceColor', 'b','MarkerSize', 17)
plot(pcl_bifurc_array(skip_two_one:end), apd_array_bifurc(skip_two_one:end), 'or', 'MarkerFaceColor', 'r','MarkerSize', 17)

% plot(pcl_bifurc_array(skip_two_one:end), apd90_2nd_last_bifurc(skip_two_one:end), 'ob', 'MarkerFaceColor', 'b','MarkerSize', 17)
% plot(pcl_bifurc_array(skip_two_one:end), apd90_array_bifurc(skip_two_one:end), 'or', 'MarkerFaceColor', 'r','MarkerSize', 17)

% plot(pcl_bifurc_array(skip_two_one:end), apd75_2nd_last_bifurc(skip_two_one:end), 'ob', 'MarkerFaceColor', 'b','MarkerSize', 17)
% plot(pcl_bifurc_array(skip_two_one:end), apd75_array_bifurc(skip_two_one:end), 'or', 'MarkerFaceColor', 'r','MarkerSize', 17)


plot(linspace(1,500,500), linspace(1,500,500),'--k', 'LineWidth', 5); %Straight line
% text(100, 240, "y=x", 'FontSize' ,35)
ylim([-1 300])
xlabel("PCL (ms)")
ylabel("APD90 (ms)")
set(gca, 'FontSize', 75)
xticks([0, 250, 1000 2000])
% legend("APD: n-1", "APD: n", 'position', [0.5, 0.5 0.2 0.2],'FontSize', 50)
set(gca,'linewidth',10, 'fontweight', 'bold')
% legend boxoff
set(gca,'TickDir','out')
% xlim([100 300])
% xticks([100 200 300])

%% Plot Restitution Curve (APD,n+1 vs DI,n)
figure
set(gcf, 'Color', 'white')
hold on
di_array_bifurc = pcl_bifurc_array - apd_array_bifurc;
di_2nd_array_bifurc = pcl_bifurc_array - apd_2nd_last_bifurc;

plot(di_2nd_array_bifurc(1:end-1), apd_2nd_last_bifurc(2:end), 'ob', 'MarkerSize', 17, 'MarkerFaceColor', 'b')
plot(di_array_bifurc(1:end-1), apd_array_bifurc(2:end), 'or', 'MarkerSize', 17, 'MarkerFaceColor', 'r')
plot(linspace(1,500,500), linspace(1,500,500),'--k', 'LineWidth', 5); %Straight line


ylim([-1 300])
xlabel("DI:n (ms)")
ylabel("APD:n+1 (ms)")
set(gca, 'FontSize', 75)
xticks([0, 250, 1000 2000])
legend("APD: n-1", "APD: n", 'position', [0.5, 0.5 0.2 0.2],'FontSize', 50)
set(gca,'linewidth',10, 'fontweight', 'bold')
legend boxoff
set(gca,'TickDir','out')

function cap_str = capitalize(in_str)
    cap_str = regexprep(in_str,'(\<[a-z])','${upper($1)}');

end
