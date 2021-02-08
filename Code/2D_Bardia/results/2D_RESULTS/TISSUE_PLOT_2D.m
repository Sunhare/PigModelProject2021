tis_data = load("2D_CONTROL_results.txt");

NX = 100;
NY = 100;

video = VideoWriter('2D_CONTROL_ECTOPIC.mp4', 'MPEG-4');
video.FrameRate = 20;

open(video)

for i= 1:size(tis_data,1)
    tis_slice = tis_data(i,:);
    tis_slice = reshape(tis_slice, NX, NY)';
    surf(tis_slice)
    shading interp
    view(2)
    caxis([-90 40])
    zlim([-90 60])
    colorbar
    set(gca,'visible','off')
    
    frame = getframe(gcf);
    fprintf("%d\n", i)
    writeVideo(video, frame);
    
end

close(video)

%% Quick Plot
c_tis_data = load("2D_CONTROL_results.txt");
r_tis_data = load("2D_REMOTE_results.txt");
b_tis_data = load("2D_BORDER_results.txt");

figure
set(gcf, 'Color' ,'w')
hold on
t_tis_data = 0:10:2000;
plot(t_tis_data, c_tis_data(:,2500), 'k', 'LineWidth', 5)
plot(t_tis_data, r_tis_data(:,2500), 'g', 'LineWidth', 5)
plot(t_tis_data, b_tis_data(:,2500) ,'r', 'LineWidth', 5)

title("Cell (50,50) Comparison")
ylabel("Voltage (mV)")
xlabel("Time (ms)")
legend("Control","Remote-HF", "Border-HF")
set(gca, 'FontSize', 25)

