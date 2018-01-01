CCW_SLOW = 1;
CW_SLOW = 2;
CCW_FAST = 3;
CW_FAST = 4;
FORWARD_MOVE = 5;
BACKWARD_MOVE = 6;
STOP = 7;

ANGLE_INC_STEP = 0.2;

PLOT_SAMPLE = 10;

SLOW_INCRE = ANGLE_INC_STEP;
FAST_INCRE = ANGLE_INC_STEP * 2;
SLOW_DECR = ANGLE_INC_STEP * -1;
FAST_DECR = ANGLE_INC_STEP * -2;

NORTH = 270;
SOUTH = 90;
EAST = 0;
WEST = 180;
NONE = -1;

INIT_COMP_VALUE = NORTH; %degree
MAX_SPEED = 850; %mm/s
ROB_LENG = 30; %cm
SAMPLE_TIME = 0.001; %sec

ROB_WHEEL_R = .15;
STEP_SIZE = 5;

initYSim = 45;
initXSim = 45;


ERRVAL = 5;

roomDrawing

INIT_Y = round(roomSize/2);
INIT_X = round(roomSize/2);