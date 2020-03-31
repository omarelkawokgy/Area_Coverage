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
CONST_EndOfLineEnableFlg = boolean(false);
CONST_EnDelay = uint16(10 * 1000);
CONST_EOL_SlowPwm = uint8(100);
CONST_EOL_MedPwm = uint8(150);
CONST_EOL_FastPwm = uint8(200);
CONST_EOL_SFastPwm = uint8(250);
CONST_EOL_ME_Ticks = uint16(150); %original 15000
CONST_MinDistError_mm = uint16(5);
ENU_DIAG_COMP = uint8(1);
ENU_DIAG_ENCOD = uint8(2);
ENU_DIAG_ULS = uint8(3);
ENU_DIAG_PUMP = uint8(4);
ENU_DIAG_BLTOTH = uint8(5);
ENU_DIAG_ANGLE_CALIB = uint8(6);
ENU_DIAG_NONE = uint8(7);
CONST_DIAG_FINISH_FLG = uint8(8);
CONST_DIAG_UNCONFIRM = uint8(9);
CAL_PwmMoveThd_mm = uint8(180);

%% General constants
CONST_TWO_F32 = single(2);
CONST_PI_F32 = single(pi);
CONST_ZERO_UINT16 = uint16(0);
CONST_ZERO_F32 = single(0);
CONST_ONE_F32 = single(1);
CONST_ONE_INT32 = int32(1);
CONST_NEG_ONE_INT32 = int32(-1);
CONST_ONE_UINT16 = uint16(1);
CONST_ZERO_THD_F32 = single(0.0000001);
CONST_FALSE = boolean(false);
COSNT_TRUE = boolean(true);
CONST_ENCOD_TIMER_FAULT = uint8(10);
CONST_VEL_TIMEOUT = uint8(100);
CONST_COMPASS_DIAG_FIN_TIMER = uint8(10);
CONST_ERROR_TOLERANCE = uint8(6);
CONST_MODES_TOLERANCE = uint8(5);
CONST_ZGZAG_CNT_THD = uint8(2);
CONST_GTSP_HITCNT_THD = uint8(3);
CONST_SNSR_VIEW_PERC = single(0.2);
CONST_MOVE_STABLE_CNT = uint8(5);
CONST_UTURN_CNT_THD = uint8(2);
CONST_TARGET_REACHED_TIMER = uint8(100);
CONST_CONFIRM_TIME_STOP = uint8(5);
CONST_STUCK_CONFIRM_THD = uint8(2);



%% General Calibration
CAL_mmPerTickPerTs = CAL_mm_PER_tick/CAL_EncoderSampleTime;

%% Routines Enum
ENU_GTSP = uint8(25);
ENU_ZIGZAG = uint8(26);
ENU_END = uint8(27);
ENU_DIAG = uint8(28);

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

ENU_PASSED = uint8(1);
ENU_FAILED = uint8(2);
ENU_FINISHED = uint8(4);
ENU_TEST_NOT_CONFIRMED = uint8(3);

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
CAL_Wheel2WheelDist_mm = uint16(250);
CAL_ROBO_LENG = uint8(CAL_Wheel2WheelDist_mm/10);
CAL_ROBO_LENG_mm = CAL_Wheel2WheelDist_mm;
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
CONST_OVERFLOW_THD_UINT16 = uint16(5);

CAL_SAMPLE_TIME = single(0.005);
CAL_APP_Ticks_Sec = uint8(5);
CAL_DIAG_Ticks_Sec = uint8(50);
CAL_EncoderSampleTime = single(0.001);
CAL_Init_timer = uint16(2/CAL_SAMPLE_TIME); %450 ms to initialize filters

CAL_NORTH = uint16(270);
CAL_NORTH_rad = single((270*pi)/180);
CAL_EAST = uint16(0);
CAL_WEST = uint16(180);
CAL_SOUTH = uint16(90);



%% ULS filter calibration
CAL_FilterBufferSize = uint8(4);
CAL_ULS_UnconnectedBlks = uint8(10);

%% Encoder Calibration data
CAL_SingleStepMulti = 0.75;
CONST_CounterInit = uint8(0);
CAL_SingleStepTicks = uint16(470);
CAL_SingleTurnTicks = uint16(470);
CAL_WheelDiameter_cm = uint8(12);
CAL_WheelCircumference_cm = pi * single(CAL_WheelDiameter_cm);
CAL_tick_PER_mm = single(CAL_SingleTurnTicks) / single(CAL_WheelCircumference_cm*10);
CAL_hitBackwardDist_mm = single(150);
CAL_stopTime_sec = single(0.1);
CAL_mm_PER_tick = single(1 / CAL_tick_PER_mm);

%% main routines calibrations
CAL_GTSPgapCounter = uint8(100); %time in ticks
CAL_GTSPdelayStart = uint8(200); %time in ticks
CAL_ZgZgCounterThd = uint8(2);

%% movement Calibrations
CAL_forwardThetaThd = uint8(200);
CONST_Zero = int16(0);
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
CAL_ProcessNoise = single(1.5);
CAL_procNoiseVelKF = single(1.5);
CAL_MeasNoiseVelKF = single(0.8);
CAL_MeasureNoise = single(1.2);
CAL_FilterResetThd = int16(100);

%% motor handler config
CAL_forwardStartIncr = single(0.001);
CAL_forwardErrorLimit = single(0.5);
CAL_ErrorUpperLimit = single(2);
CAL_ErrorLowerLimit = single(-2);
CAL_backwardErrorVal = single(0.5);
CONST_noVelocity = int16(0);
CAL_risingStep_pwmPerSample = single(CAL_ErrorUpperLimit * 0.05);
CAL_fallingStep_pwmPerSample = single(CAL_ErrorLowerLimit * 0.1);
CAL_straightLineErrorAllowed_f32 = single(CAL_ErrorUpperLimit);