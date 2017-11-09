lineLength = ROB_LENG;
for i = 1: length(X_OUT.Data)
    
    plot(X_OUT.Data(i), Y_OUT.Data(i), '*', 'MarkerSize', 10);
    hold on
    opleft = sind(Theta_OUT.Data(i)+90) * (lineLength/2);
    adjleft = cosd(Theta_OUT.Data(i)+90) * (lineLength/2);
    yend = Y_OUT.Data(i) + opleft;
    xend = X_OUT.Data(i) + adjleft;
    start = [X_OUT.Data(i) xend];
    finish = [Y_OUT.Data(i) yend];
    plot(start, finish, 'LineWidth', 3)
    plot(xend, yend, 'or')
    opright = sind(Theta_OUT.Data(i)-90) * (lineLength/2);
    adjright = cosd(Theta_OUT.Data(i)-90) * (lineLength/2);
    yend = Y_OUT.Data(i) + opright;
    xend = X_OUT.Data(i) + adjright;
    start = [X_OUT.Data(i) xend];
    finish = [Y_OUT.Data(i) yend];
    plot(start, finish, 'LineWidth', 3)
    plot(xend, yend, 'or')
%     hold off
    xlim([0 roomSize]);
    ylim([0 roomSize]);
    grid on
    grid minor
    pause(0.000001);
end