tis_data = load("2D_CONTROL_results.txt");

NX = 100;
NY = 100;

video = VideoWriter('2D_CONTROL.mp4', 'MPEG-4');
video.FrameRate = 20;
% video.FileFormat = 'mp4';     

open(video)

for i= 1:size(tis_data,1)
% for i= 1
    tis_slice = tis_data(i,:);
    tis_slice = reshape(tis_slice, NX, NY)';
    surf(tis_slice)
    shading interp
    view(2)
    caxis([-90 -70])
    zlim([-90 60])
    colorbar
    set(gca,'visible','off')
    
    frame = getframe(gcf);
    fprintf("%d\n", i)
    writeVideo(video, frame);
    
end

close(video)

<<<<<<< HEAD
%% Quick Plot
c_tis_data = load("2D_CONTROL_results.txt");
r_tis_data = load("2D_REMOTE_results.txt");
b_tis_data = load("2D_BORDER_results.txt");

figure
set(gcf, 'Color' ,'w')
hold on
plot(c_tis_data(:,2500), 'k', 'LineWidth', 5)
plot(r_tis_data(:,2500), 'g', 'LineWidth', 5)
plot(b_tis_data(:,2500) ,'r', 'LineWidth', 5)

title("Cell ID: 2500 Comparison")
ylabel("Voltage (mV)")
xlabel("Time (100 ms)")
legend("Control","Remote-HF", "Border-HF")
set(gca, 'FontSize', 25)
=======
>>>>>>> parent of 1ba6ac1... Successful 2D Control Ectopic Beat

