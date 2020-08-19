clear all
answer = questdlg('Initialize for?', ...
	'Initalization Type', ...
	'Production','Simulation','Cancel','Simulation');
addpath('..\SRC')
addpath(genpath('..\..\COMH'))
addpath(genpath('..\..\MAPH'))
addpath(genpath('..\..\MOTH'))
addpath(genpath('..\..\MOVH'))
addpath(genpath('..\..\POSH'))
addpath(genpath('..\..\ROTH'))
addpath(genpath('..\..\SCAN'))
addpath(genpath('..\..\DSCA'))
addpath(genpath('..\..\MOMO'))
addpath(genpath('..\..\COML'))
addpath(genpath('..\..\..\Scripts'))

ControlInit;
if strcmp(answer, 'Simulation')
    MotorConfigurationSheet;
    Signals_DD;
    ConvertParam;
    AreaCoverageCalib;
	Test_MotorConfigurationSheet;
elseif strcmp(answer, 'Production')
	CONST_PIN_D0 = uint8(0);
	CONST_PIN_D1 = uint8(1);
	CONST_PIN_D2 = uint8(2);
	CONST_PIN_D3 = uint8(3);

	CONST_PIN_D4 = uint8(4);
	CONST_PIN_D5 = uint8(5);
	CONST_PIN_D6 = uint8(6);
	CONST_PIN_D7 = uint8(7);

	CONST_PIN_D8 = uint8(8);
	CONST_PIN_D9 = uint8(9);
	CONST_PIN_D10 = uint8(10);
	CONST_PIN_D11 = uint8(11);

	CONST_PIN_D12 = uint8(12);
	CONST_PIN_D13 = uint8(13);

	CONST_PIN_A0 = uint8(14);
	CONST_PIN_A1 = uint8(15);
	CONST_PIN_A2 = uint8(16);
	CONST_PIN_A3 = uint8(17);
	CONST_PIN_A4 = uint8(18);
	CONST_PIN_A5 = uint8(19);
    MotorConfigurationSheet;
    Signals_DD;
    ConvertParam
end

%% Variant Handling
leftMotorEOL_variant = Simulink.Variant;
leftMotorEOL_variant.Condition = ('(VARIANT_LEFT_MOTOR_EOL_ENABLE == true) && (VARIANT_RIGHT_MOTOR_EOL_ENABLE == false)');
leftMotorEOL_DisabledVariant = Simulink.Variant;
leftMotorEOL_DisabledVariant.Condition = ('VARIANT_LEFT_MOTOR_EOL_ENABLE == false');
rightMotorEOL_variant = Simulink.Variant;
rightMotorEOL_variant.Condition = ('(VARIANT_RIGHT_MOTOR_EOL_ENABLE == true) && (VARIANT_LEFT_MOTOR_EOL_ENABLE == false)');
rightMotorEOL_DisabledVariant = Simulink.Variant;
rightMotorEOL_DisabledVariant.Condition = ('VARIANT_RIGHT_MOTOR_EOL_ENABLE == false');
motorsHandleEOL_Variant = Simulink.Variant;
motorsHandleEOL_Variant.Condition = ('(VARIANT_RIGHT_MOTOR_EOL_ENABLE == true) || (VARIANT_LEFT_MOTOR_EOL_ENABLE == true)');
MotorsEOL_DisabledVariant = Simulink.Variant;
MotorsEOL_DisabledVariant.Condition = ('(VARIANT_LEFT_MOTOR_EOL_ENABLE == false) && (VARIANT_RIGHT_MOTOR_EOL_ENABLE == false)');

debuggingFlag_variant = Simulink.Variant;
debuggingFlag_variant.Condition = ('VARIANT_DEBUGGING_ENABLE == true');

CompassSensorConnected_variant = Simulink.Variant;
CompassSensorConnected_variant.Condition = ('VARIANT_COMPASS_CONNECTED == true');