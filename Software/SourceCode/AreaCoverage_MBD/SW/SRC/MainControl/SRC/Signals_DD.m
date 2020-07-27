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