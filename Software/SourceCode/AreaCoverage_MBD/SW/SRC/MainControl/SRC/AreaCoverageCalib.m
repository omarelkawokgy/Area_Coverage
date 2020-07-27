CCW_SLOW = 1;
CW_SLOW = 2;
CCW_FAST = 3;
CW_FAST = 4;
FORWARD_MOVE = 5;
BACKWARD_MOVE = 6;

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
MAX_SPEED = 1000; %mm/s
ROB_LENG = CAL_ROBO_LENG; %cm
ROB_LENG_mm = single(CAL_ROBO_LENG*10);
ROB_LENG_m = 0.25;
SAMPLE_TIME = 0.001; %sec
gearRatio = 12;
halfWheel_mm = 60;

ROB_WHEEL_R_m = .06;
ROB_WHEEL_R_cm = ROB_WHEEL_R_m*100;
STEP_SIZE = 5;

initYSim = 50;
initXSim = 38;


ERRVAL = 5;

roomDrawing

INIT_Y = round(roomSize/2);
INIT_X = round(roomSize/2);
BLOCK_SIZE = double(CAL_BLOCK_SIZE);
ROOM_SIDE_SIZE = double(CAL_ROOM_SIDE_SIZE);

MOTOR_HIGH = CAL_MOTOR_HIGH;
MOTOR_LOW = CAL_MOTOR_LOW;

thetaMapTb5 = [0 : 0.1 : 29.9];
thetaMapTb1 = [30 : 0.1 : 99.9];
thetaMapTb2 = [100 : 1 : 200];
thetaMapTb3 = [200 : 0.05265 : 300];
thetaMapTb4 = [300.1 : 0.1 : 360];

thetaMapTb = [thetaMapTb1, thetaMapTb2, thetaMapTb3, thetaMapTb4, thetaMapTb5];
thetaMapBp = [0 : 0.1 : 360];

% NVM Handler
NVM_NORTH = uint16(CAL_NORTH);
NVM_SOUTH = uint16(CAL_SOUTH);
NVM_EAST = uint16(CAL_EAST);
NVM_WEST = uint16(CAL_WEST);
NVM_AngleStoreFlg = false;