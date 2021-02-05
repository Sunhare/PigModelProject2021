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


