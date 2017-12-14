function PlotterFunc(X, Y, Theta, roomSize, Event)

persistent init;

if isempty(init)
    init = 0;
    
    %% drawing room
    standardRoom_CM = 500; % cm
    ROBO_LENG = 30;
    roomSize = round(standardRoom_CM/ROBO_LENG + 2);
    room = uint8(ones(roomSize , roomSize)*255);

    %% Draw room Boarders
    for rowNum = 1:(roomSize)
        for colNum = 1: roomSize
            if (rowNum == 1) || (rowNum == roomSize)...
                    || (colNum == 1) || (colNum == roomSize)
    %                 || (rowNum == 2) || (rowNum == roomSize - 1)...
    %                 || (colNum == 2) || (colNum == roomSize-1)
                room(rowNum, colNum) = 0;
            end
        end
    end

    %% Draw room Obsticals

    %% insert Table
    room(4, 9) = 0;
    room(6, 9) = 0;
    room(4, 11) = 0;
    room(6, 11) = 0;

    %% insert box
    room(3:4, 4:5) = 0;

    %% insert soffa
    room(12:14, 8:13) = 0;

    %% insert LeglessTable
    room(7:11, 1:4) = 0;
room = room';
    hold off;
    clf
    empty = 255;
    busy = 0;
    hold on
    for i = 1:length(room(1, :))
        for j = 1:length(room(:, 1))
            if room(i, j) == empty
                plot(i-1, j-1, '*b');
            else if room(i,j) == busy
                    plot(i-1, j-1, 'or');
                else 
                    plot(i-1, j-1, 'x');
                end
            end
        end
    end
    axis ij
end

lineLength = round(roomSize*0.12);
plotCounter = 0;
opleft = sind(Theta+90) * (lineLength/2);
    adjleft = cosd(Theta+90) * (lineLength/2);
    yend = Y + opleft;
    xend = X + adjleft;
    start = [X xend];
    finish = [Y yend];

    opright = sind(Theta-90) * (lineLength/2);
    adjright = cosd(Theta-90) * (lineLength/2);
    if Event
        plot(X, Y, '*', 'MarkerSize', 10);
        hold on
        plot(start, finish, 'LineWidth', 3)
        plot(xend, yend, '*')
        yend = Y + opright;
        xend = X + adjright;
        start = [X xend];
        finish = [Y yend];
        plot(start, finish, 'LineWidth', 3)
        plot(xend, yend, '*')
        %hold off
        xlim([0 roomSize]);
        ylim([0 roomSize]);
        grid on
        grid minor
        plotCounter = 0;
%         axis ij
    end
    plotCounter = plotCounter + 1;
    pause(0.001);
