%% Movements Enum
FORWARD = 1;
BACKWARD = 2;
CW = 3;
CCW = 4;
STOP = 5;

% 90 and 180 degree turns Enum
MOVE_TURN_LEFT = 20;
MOVE_TURN_RIGHT = 21;
MOVE_U_TURN_RIGHT = 22;
MOVE_U_TURN_LEFT = 23;
MOVE_U_TURN = 24;

%% Heading Enum
% ROB_NORTH = 270;
% ROB_SOUTH = 90;
% ROB_EAST = 0;
% ROB_WEST = 180;
ROB_NONE = 400;



%% Routines Enum
GTSP = 25;
ZIGZAG = 26;
END = 27;

%% Sensor View Enum
FAILURE_READING = 6;
LEFT_BUSY_RIGHT_EMPTY = 7;
LEFT_EMPTY_RIGHT_BUSY = 8;
LEFT_BUSY_RIGHT_BUSY = 9;
LEFT_CLEANED_RIGHT_EMPTY = 10;
LEFT_EMPTY_RIGHT_CLEANED = 11;
LEFT_CLEANED_RIGHT_CLEANED = 12;
LEFT_CLEANED_RIGHT_BUSY = 13;
LEFT_BUSY_RIGHT_CLEANED = 14;
LEFT_EMPTY_RIGHT_EMPTY = 15;





%% Map States
BUSY = 4;
EMPTY = 3;
CLEANED = 2;
UNCOVERED = 1;

%% MapConfig
BLOCK_SIZE = 20;
ROOM_SIDE_SIZE = 20;

roomSize = ROOM_SIDE_SIZE;
map = uint8(ones(ROOM_SIDE_SIZE , ROOM_SIDE_SIZE)*UNCOVERED);

%% Draw room Boarders
for rowNum = 1:(roomSize)
    for colNum = 1: roomSize
        if (rowNum == 1) || (rowNum == roomSize)...
                || (colNum == 1) || (colNum == roomSize)
%                 || (rowNum == 2) || (rowNum == roomSize - 1)...
%                 || (colNum == 2) || (colNum == roomSize-1)
            map(rowNum, colNum) = BUSY;
        end
    end
end

%% RobotConfig
ROB_DIAMETER = 30;
% Angle error allowed value
ROB_ERRVAL = 5;
initX = uint8((ROOM_SIDE_SIZE/2) - 1);
initY = initX;

MOTOR_HIGH = 254;
MOTOR_LOW = 0;

NO_ERROR = 0;
ALLOWED_ERROR_VALUE = 0.02;