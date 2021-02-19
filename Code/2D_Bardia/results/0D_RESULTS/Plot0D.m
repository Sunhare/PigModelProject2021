cdata = load("CONTROL_results.txt");
rdata = load("REMOTE_results.txt");
bdata = load("BORDER_results.txt");

for i = 1:3
    if i ==1
        data = cdata;
    elseif i==2
        data = rdata;
    elseif i ==3
        data = bdata;
    end
    t = data(:,1);
    v = data(:,2);
    hold on
    plot(t,v,'LineWidth', 3)
end
legend("Control","Remote","Border")