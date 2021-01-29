clear all;
close all;
%% Save Data
cd '/Users/satolab/Desktop/ShannonPigModel/Figures_Adobe/EAD_ANALYSIS'

% save('BORDER_IKS_50IKR_EAD.mat','MAT_EAD_MAT')
%% Load Data
%Data file format: CELLTYPE _ ION CHANNEL EAD ANALYSIS _ "EAD" . mat
% e.g. CONTROL_IKR_EAD = ICaL vs IKr plot of control cell

%Parameters
cell_type = 3; %1 = Control, 2 = Remote, 3 = Border
ion_sim = 1; %1 = IKR, 2 = IKS, 3 = IKS w/ 50% IKr


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

ead_data = cell2mat(struct2cell(load(cell_name+"_"+ion_name+"_"+"EAD.MAT")));

%ead_data structure
%Col 1 = ICaL Scale
%Col 2 = IKr Scale
%Col 3 = Avg # of peaks b/w last two beats (a.k.a number of EADs)
%Col 4 = Avg APD of 2nd to last and last apd (AVG of col 5 and 6)
%Col 5 = APD 2nd to last beat
%COl 6 = APD of the last beat
%% Plot

figure('Position', [0 0 800 800])
set(gcf,'Color','white'); 

y = 1:-0.025:0.0;
x = linspace(1,4,length(y));

%This is where you choose what the z axis is plotting
zz = reshape(max([ead_data(:,5), ead_data(:,6)]'), [length(y) length(x)]);

[xx,yy] = meshgrid(x,y);

colormap jet
surf(xx,yy,zz)
shading flat
%colorbar
view(2)

%xlabel("I_C_a_L")
set(gca, 'FontSize', 32)
set(gca, 'FontWeight', 'bold')


c_name = convertStringsToChars(cell_name);
 if cell_type == 1
     caxis([800 1800])
 elseif cell_type == 2
     caxis([800 2000])
 elseif cell_type == 3
     caxis([500 1600])
 end
if ion_sim == 1
%    ylabel("I_K_r")
%    caxis([min(min(zz)) 2200])    
%     caxis([800 1500]);
%    title(strcat(upper(c_name(1)), lower(c_name(2:end)))+" I_K_r")
%    print('./'+lower(cell_name)+'_ead_map_cal_ikr', '-painters', '-dsvg')

    dpi=300;
    set(gcf, 'PaperUnits', 'inches', 'PaperPosition', [0 0 4000 4000]/dpi);
    print(gcf,'-dpng',sprintf('-r%d',dpi), './'+lower(cell_name)+'_ead_map_cal_ikr');

elseif ion_sim == 2
%     caxis([200 800]);
    dpi=300;
    set(gcf, 'PaperUnits', 'inches', 'PaperPosition', [0 0 4000 4000]/dpi);
    print(gcf,'-dpng',sprintf('-r%d',dpi), './'+lower(cell_name)+'_ead_map_cal_iks');

%     ylabel("I_K_s")
%     title(strcat(upper(c_name(1)), lower(c_name(2:end)))+" I_K_s")
%     print('./'+lower(cell_name)+'_ead_map_cal_iks', '-painters', '-dsvg')
elseif ion_sim == 3
    dpi=300;
    set(gcf, 'PaperUnits', 'inches', 'PaperPosition', [0 0 4000 4000]/dpi);
    print(gcf,'-dpng',sprintf('-r%d',dpi), './'+lower(cell_name)+'_ead_map_cal_iks_50ikr');

%     ylabel("I_K_s ( 50% I_K_r )")
%     title(strcat(upper(c_name(1)), lower(c_name(2:end)))+" I_K_s (50% I_K_r)")
%     print('./'+lower(cell_name)+'_ead_map_cal_iks_050ikr', '-painters', '-dsvg')
end
