function room_V3()
ROOM_SIDE_SIZE = 20;
BLOCK_SIZE = 20;
persistent flag;
persistent room;
   side_size = ROOM_SIDE_SIZE * (BLOCK_SIZE/4);

if isempty(flag)
    flag = false;
    room = uint8(ones(side_size , side_size)*255);
end

if flag == false
   flag = true;
%     room = uint8(ones(ROOM_SIDE_SIZE , ROOM_SIDE_SIZE)*255);

    %% Draw room Boarders
    for rowNum = 1:(side_size)
        for colNum = 1: side_size
            if (rowNum <= BLOCK_SIZE/4) || (rowNum >= (side_size - BLOCK_SIZE/4))...
                    || (colNum <= BLOCK_SIZE/4) || (colNum >= side_size - BLOCK_SIZE/4)
    %                 || (rowNum == 2) || (rowNum == roomSize - 1)...
    %                 || (colNum == 2) || (colNum == roomSize-1)
                room(rowNum, colNum) = 0;
            end
        end
    end

    %% Draw room Obsticals
    scale = 5;
    %% insert Table
    room((9*scale - scale/2) + 0.5:(11*scale + scale/2) + 0.5, (7*scale - scale/4) + 0.5:(13*scale + scale/4 )+ 0.5) = 0;
 
    %% insert chairs
    room((17*scale - scale/2) + 0.5:(19*scale + scale/2) + 0.5, (5*scale - (scale)/2) + 0.5:(8*scale + (scale)/2 )+ 0.5) = 0;

%     room((15.5*scale - scale/2) + 0.5:(17.5*scale + scale/2) + 0.5, (13*scale - (scale)/2) + 0.5:(16*scale + (scale)/2 )+ 0.5) = 0;

    room((9*scale - scale/2) + 0.5:(12*scale + scale/2) + 0.5, (17*scale - (scale)/2) + 0.5:(19*scale + (scale)/2 )+ 0.5) = 0;
    
    x = (14:0.1:16.5);
    y = (16:0.1:19);
    depth = 5;
    for j = 1:depth*scale
        for i = 1:length(x)
            room(uint8((x(i)*scale - scale/2) + 0.5), uint8((y(i)*scale - scale/2) + 0.5)) = 0;
        end
        x = x + 0.1;
        y = y - 0.1;
    end
    
    
    x = (2:0.1:5);
    y = (16.5:0.1:19.5);
    depth = 5;
    for j = 1:depth*scale
        for i = 1:length(x)
            room(uint8((x(i)*scale - scale/2) + 0.5), uint8((y(i)*scale - scale/2) + 0.5)) = 0;
        end
        x = x + 0.1;
        y = y - 0.1;
    end
    
    room((2*scale - scale/2) + 0.5:(4*scale + scale/2) + 0.5, (6*scale - (scale)/2) + 0.5:(13*scale + (scale)/2 )+ 0.5) = 0;
  
    roomOut = room;
else
    roomOut = room;
end
PlotterFunc(roomOut, 50, 50, 0, ROOM_SIDE_SIZE, 1, BLOCK_SIZE)

function PlotterFunc(room, X, Y, Theta, ROOM_SIDE_SIZE, clock, BLOCK_SIZE)

persistent init;
% persistent fig;

% if isempty(fig)
% %     fig = figure;
% end
figure
if isempty(init)
    init = 0;
    %room = uint8(room');
    hold off;
    clf
    empty = 255;
    busy = 0;
    hold on
    offset = 0;
    for i = 1:length(room(1, :))
        for j = 1:length(room(:, 1))
            if room(i, j) == empty
%                 plot(i - offset, j - offset, '*b');
            else if room(i,j) == busy
                    plot(i - offset, j - offset, '.r');
                else 
                    plot(i - offset, j - offset, 'x');
                end
            end
        end
    end
    axis ij
end


% delta = clock - init;
% if(delta) >= 0.5
% %     figure(fig);
%     init = clock;
%     Xplot = double(X);
%     Yplot = double(Y);
%         if clock
%             lineLength = double(BLOCK_SIZE*0.25);
%             opleft = double(sind(Theta+90) * (lineLength/2));
%             adjleft = double(cosd(Theta+90) * (lineLength/2));
%             yend = double(Yplot) + opleft;
%             xend = double(Xplot) + adjleft;
%             start = [double(Xplot) xend];
%             finish = [double(Yplot) yend];
% 
%             opright = double(sind(Theta-90) * (lineLength/2));
%             adjright = double(cosd(Theta-90) * (lineLength/2));
% 
%             plot(double(Xplot), double(Yplot), 'r*', 'MarkerSize', 10);
%             hold on
%             plot(start, finish, 'g', 'LineWidth', 3)
%             plot(xend, yend, 'bx')
%             yend = double(Yplot) + opright;
%             xend = double(Xplot) + adjright;
%             start = [double(Xplot) xend];
%             finish = [double(Yplot) yend];
%             plot(start, finish, 'g','LineWidth', 3)
%             plot(xend, yend, 'bx')
% %             hold off
% %             xlim([-1*((ROOM_SIDE_SIZE * BLOCK_SIZE)/2) - 50 (ROOM_SIDE_SIZE * BLOCK_SIZE)/2 + 50]);
% %             ylim([-1*((ROOM_SIDE_SIZE * BLOCK_SIZE)/2) - 50 (ROOM_SIDE_SIZE * BLOCK_SIZE)/2 + 50]);
%             xlim([0 100]);
%             ylim([0 100]);
%             grid on
%             grid minor
%     %         axis ij
%         end
% end

