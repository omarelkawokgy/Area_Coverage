%% Movements Enum
ENU_FORWARD = uint8(1);
ENU_BACKWARD = uint8(2);
ENU_CW = uint8(3);
ENU_CCW = uint8(4);
ENU_STOP = uint8(5);

% 90 and 180 degree turns Enum
ENU_MOVE_TURN_LEFT = uint8(20);
ENU_MOVE_TURN_RIGHT = uint8(21);
ENU_MOVE_U_TURN_RIGHT = uint8(22);
ENU_MOVE_U_TURN_LEFT = uint8(23);
ENU_MOVE_U_TURN = uint8(24);

%% Heading Enum
% ROB_NORTH = 270;
% ROB_SOUTH = 90;
% ROB_EAST = 0;
% ROB_WEST = 180;
ENU_ROB_NONE = uint16(400);

%% DIAG EOL Calibrations
CONST_EndOfLineEnableFlg = boolean(true);
CONST_EnDelay = uint16(10 * 1000);
CONST_EOL_SlowPwm = uint8(100);
CONST_EOL_MedPwm = uint8(150);
CONST_EOL_FastPwm = uint8(200);
CONST_EOL_SFastPwm = uint8(250);
CONST_EOL_ME_Ticks = uint16(50); %original 15000


%% Routines Enum
ENU_GTSP = uint8(25);
ENU_ZIGZAG = uint8(26);
ENU_END = uint8(27);

%% Sensor View Enum
ENU_FAILURE_READING = uint8(6);
ENU_LEFT_BUSY_RIGHT_EMPTY = uint8(7);
ENU_LEFT_EMPTY_RIGHT_BUSY = uint8(8);
ENU_LEFT_BUSY_RIGHT_BUSY = uint8(9);
ENU_LEFT_CLEANED_RIGHT_EMPTY = uint8(10);
ENU_LEFT_EMPTY_RIGHT_CLEANED = uint8(11);
ENU_LEFT_CLEANED_RIGHT_CLEANED = uint8(12);
ENU_LEFT_CLEANED_RIGHT_BUSY = uint8(13);
ENU_LEFT_BUSY_RIGHT_CLEANED = uint8(14);
ENU_LEFT_EMPTY_RIGHT_EMPTY = uint8(15);

ENU_PASSED = 1;
ENU_FAILED = 2;

%% Map States
ENU_BUSY = uint8(4);
ENU_EMPTY = uint8(3);
ENU_CLEANED = uint8(2);
ENU_UNCOVERED = uint8(1);

%% MapConfig
CAL_BLOCK_SIZE = uint8(20);
CAL_BLOCK_SIZE_mm = uint8(200);
CAL_ROOM_SIDE_SIZE = uint8(20);

CAL_roomSize = CAL_ROOM_SIDE_SIZE;
CAL_map = uint8(ones(CAL_ROOM_SIDE_SIZE , CAL_ROOM_SIDE_SIZE)*1); %1 for ENU_UNCOVERED

%% Draw room Boarders
for rowNum = 1:(CAL_roomSize)
    for colNum = 1: CAL_roomSize
        if (rowNum == 1) || (rowNum == CAL_roomSize)...
                || (colNum == 1) || (colNum == CAL_roomSize)
%                 || (rowNum == 2) || (rowNum == roomSize - 1)...
%                 || (colNum == 2) || (colNum == roomSize-1)
            CAL_map(rowNum, colNum) = ENU_BUSY;
        end
    end
end

%% RobotConfig
% ROB_DIAMETER = 30;
CAL_ROBO_LENG = uint8(30);
CAL_ROBO_LENG_mm = uint16(300);
% Angle error allowed value
CAL_ROB_ERRVAL = uint8(5);
CAL_initX = uint8((CAL_ROOM_SIDE_SIZE/2) - 1);
CAL_initY = CAL_initX;

CAL_MOTOR_HIGH = uint8(126);
CAL_MOTOR_LOW = uint8(0);

CAL_NO_ERROR = uint8(0);

CAL_thetaGain = uint8(100);
CAL_halfCircle_DEG = uint16(180);
CAL_fullCircle_DEG = uint16(360);

CAL_SAMPLE_TIME = single(0.005);
CAL_APP_Ticks_Sec = uint8(5);
CAL_EncoderSampleTime = double(0.001);

CAL_NORTH = uint16(270);
CAL_EAST = uint16(0);
CAL_WEST = uint16(180);
CAL_SOUTH = uint16(90);

%% ULS filter calibration
CAL_FilterBufferSize = uint8(4);

%% Encoder Calibration data
CAL_SingleStepMulti = 0.75;
CONST_CounterInit = uint8(0);
CAL_SingleStepTicks = uint16(1100);
CAL_tick_PER_mm = single(CAL_SingleStepTicks) / single(CAL_BLOCK_SIZE_mm);
CAL_hitBackwardDist_mm = single(100);
CAL_stopTime_sec = single(0.1);
CAL_mm_PER_tick = single(1 / CAL_tick_PER_mm);

%% main routines calibrations
CAL_GTSPgapCounter = uint8(100); %time in ticks
CAL_GTSPdelayStart = uint8(200); %time in ticks
CAL_ZgZgCounterThd = uint8(2);

%% movement Calibrations
CAL_forwardThetaThd = uint8(200);

%error calibrations
CONST_NegOne = int16(-1);
CONST_ZeroDeg = int16(0); 
CONST_EnableDelay = boolean(1);
CAL_Ki = single(0.000025);
CAL_Kp = single(4);
CAL_Kd = single(0.002);
CAL_ALLOWED_ERROR_VALUE = single(0.02);

%% compass handler config
% filter calibrations
CAL_ProcessNoise = single(1.009);
CAL_MeasureNoise = single(2);
CAL_FilterResetThd = int16(100);

%% motor handler config
CAL_forwardStartIncr = single(0.001);
CAL_forwardErrorLimit = single(0.5);
CAL_ErrorUpperLimit = single(2);
CAL_ErrorLowerLimit = single(-2);
CAL_backwardErrorVal = single(0.5);
CONST_noVelocity = int16(0);