
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

%% show Map
 imshow(room,'InitialMagnification','fit')