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
ROB_NORTH = 270;
ROB_SOUTH = 90;
ROB_EAST = 0;
ROB_WEST = 180;
ROB_NONE = 400;
ROB_ERRVAL = 401;

%% Routines Enum
GTSP = 25;
ZIGZAG = 26;

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
BUSY = 16;
EMPTY = 17;
CLEANED = 18;
UNCOVERED = 19;

map = ones(19, 19)*EMPTY;

map(10, 6) = CLEANED;
map(10, 4) = BUSY;

%% RobotConfig
ROB_DIAMETER = 30;

%% MapConfig
BLOCK_SIZE = 20;
