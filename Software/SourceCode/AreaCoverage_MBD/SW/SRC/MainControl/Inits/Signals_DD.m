%% Four Directions Signals
ROB_NORTH = Simulink.Signal;
ROB_NORTH.DataType = 'int16';
ROB_NORTH.Min = 0;
ROB_NORTH.Max = 360;
ROB_NORTH.Unit = 'deg';

ROB_SOUTH = Simulink.Signal;
ROB_SOUTH.DataType = 'int16';
ROB_SOUTH.Min = 0;
ROB_SOUTH.Max = 360;
ROB_SOUTH.Unit = 'deg';

ROB_EAST = Simulink.Signal;
ROB_EAST.DataType = 'int16';
ROB_EAST.Min = 0;
ROB_EAST.Max = 360;
ROB_EAST.Unit = 'deg';

ROB_WEST = Simulink.Signal;
ROB_WEST.DataType = 'int16';
ROB_WEST.Min = 0;
ROB_WEST.Max = 360;
ROB_WEST.Unit = 'deg';

thetaCompass = Simulink.Signal;
thetaCompass.DataType = 'int16';
thetaCompass.Min = 0;
thetaCompass.Max = 360;
thetaCompass.Unit = 'deg';

pumperHit_BOOL = Simulink.Signal;
pumperHit_BOOL.DataType = 'boolean';
pumperHit_BOOL.Min = 0;
pumperHit_BOOL.Max = 1;
pumperHit_BOOL.Unit = '';
pumperHit_BOOL.CoderInfo.StorageClass = 'SimulinkGlobal';

ULSL_cm = Simulink.Signal;
ULSL_cm.DataType = 'uint16';
ULSL_cm.Min = 0;
ULSL_cm.Max = 600;
ULSL_cm.Unit = 'cm';

ULSR_cm = Simulink.Signal;
ULSR_cm.DataType = 'uint16';
ULSR_cm.Min = 0;
ULSR_cm.Max = 600;
ULSR_cm.Unit = 'cm';

rightEncoderTicks_uint16 = Simulink.Signal;
rightEncoderTicks_uint16.DataType = 'uint16';
rightEncoderTicks_uint16.Min = 0;
rightEncoderTicks_uint16.Max = 200;
rightEncoderTicks_uint16.Unit = '';
rightEncoderTicks_uint16.CoderInfo.StorageClass = 'SimulinkGlobal';

leftEncoderTicks_uint16 = Simulink.Signal;
leftEncoderTicks_uint16.DataType = 'uint16';
leftEncoderTicks_uint16.Min = 0;
leftEncoderTicks_uint16.Max = 200;
leftEncoderTicks_uint16.Unit = '';
leftEncoderTicks_uint16.CoderInfo.StorageClass = 'SimulinkGlobal';

leftPosPin = Simulink.Signal;
leftPosPin.DataType = 'uint8';
leftPosPin.Min = 0;
leftPosPin.Max = 255;
leftPosPin.Unit = 'volt';

leftNegPin = Simulink.Signal;
leftNegPin.DataType = 'uint8';
leftNegPin.Min = 0;
leftNegPin.Max = 255;
leftNegPin.Unit = 'volt';

rightPosPin = Simulink.Signal;
rightPosPin.DataType = 'uint8';
rightPosPin.Min = 0;
rightPosPin.Max = 255;
rightPosPin.Unit = 'volt';

rightNegPin = Simulink.Signal;
rightNegPin.DataType = 'uint8';
rightNegPin.Min = 0;
rightNegPin.Max = 255;
rightNegPin.Unit = 'volt';

angleCalib_NORTH = Simulink.Signal;
angleCalib_NORTH.DataType = 'uint16';
angleCalib_NORTH.Min = 0;
angleCalib_NORTH.Max = 360;
angleCalib_NORTH.Unit = 'deg';

angleCalib_SOUTH = Simulink.Signal;
angleCalib_SOUTH.DataType = 'uint16';
angleCalib_SOUTH.Min = 0;
angleCalib_SOUTH.Max = 360;
angleCalib_SOUTH.Unit = 'deg';

angleCalib_EAST = Simulink.Signal;
angleCalib_EAST.DataType = 'uint16';
angleCalib_EAST.Min = 0;
angleCalib_EAST.Max = 360;
angleCalib_EAST.Unit = 'deg';

angleCalib_WEST = Simulink.Signal;
angleCalib_WEST.DataType = 'uint16';
angleCalib_WEST.Min = 0;
angleCalib_WEST.Max = 360;
angleCalib_WEST.Unit = 'deg';

angleCalibStatus = Simulink.Signal;
angleCalibStatus.DataType = 'uint8';
angleCalibStatus.Min = 0;
angleCalibStatus.Max = 5;
angleCalibStatus.Unit = '';

redLED_BOOL = Simulink.Signal;
redLED_BOOL.DataType = 'boolean';
redLED_BOOL.Min = 0;
redLED_BOOL.Max = 1;
redLED_BOOL.Unit = '';

greenLED_BOOL = Simulink.Signal;
greenLED_BOOL.DataType = 'boolean';
greenLED_BOOL.Min = 0;
greenLED_BOOL.Max = 1;
greenLED_BOOL.Unit = '';

NVM_AngleStoreFlg = Simulink.Signal;
NVM_AngleStoreFlg.DataType = 'boolean';
NVM_AngleStoreFlg.Min = 0;
NVM_AngleStoreFlg.Max = 1;
NVM_AngleStoreFlg.Unit = '';
NVM_AngleStoreFlg.Dimensions = 1;

NVM_NORTH = Simulink.Signal;
NVM_NORTH.DataType = 'int16';
NVM_NORTH.Min = -20;
NVM_NORTH.Max = 360;
NVM_NORTH.Unit = 'deg';
NVM_NORTH.Dimensions = 1;

NVM_SOUTH = Simulink.Signal;
NVM_SOUTH.DataType = 'int16';
NVM_SOUTH.Min = -20;
NVM_SOUTH.Max = 360;
NVM_SOUTH.Unit = 'deg';
NVM_SOUTH.Dimensions = 1;

NVM_EAST = Simulink.Signal;
NVM_EAST.DataType = 'int16';
NVM_EAST.Min = -20;
NVM_EAST.Max = 360;
NVM_EAST.Unit = 'deg';
NVM_EAST.Dimensions = 1;

NVM_WEST = Simulink.Signal;
NVM_WEST.DataType = 'int16';
NVM_WEST.Min = -20;
NVM_WEST.Max = 360;
NVM_WEST.Unit = 'deg';
NVM_WEST.Dimensions = 1;