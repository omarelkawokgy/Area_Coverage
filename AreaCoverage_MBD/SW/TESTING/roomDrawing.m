
standardRoom_CM = 400; % cm
ROBO_LENG = 30;
roomSize = round(standardRoom_CM/ROBO_LENG + 2)*10;
room = uint8(ones(roomSize , roomSize)*255);

%% Draw room Boarders
for rowNum = 1:(roomSize)
    for colNum = 1: roomSize
        if (rowNum == 1) || (rowNum == roomSize)...
                || (colNum == 1) || (colNum == roomSize)
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
room(7:11, 1:4) = 1;

%% show Map
 imshow(room,'InitialMagnification','fit')