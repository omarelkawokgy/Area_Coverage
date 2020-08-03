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

leftEncoderTicks_uint16 = Simulink.Signal;
leftEncoderTicks_uint16.DataType = 'uint16';
leftEncoderTicks_uint16.Min = 0;
leftEncoderTicks_uint16.Max = 200;
leftEncoderTicks_uint16.Unit = '';