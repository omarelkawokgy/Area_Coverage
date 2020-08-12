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
	PIN_D0 = uint8(0);
	PIN_D1 = uint8(1);
	PIN_D2 = uint8(2);
	PIN_D3 = uint8(3);

	PIN_D4 = uint8(4);
	PIN_D5 = uint8(5);
	PIN_D6 = uint8(6);
	PIN_D7 = uint8(7);

	PIN_D8 = uint8(8);
	PIN_D9 = uint8(9);
	PIN_D10 = uint8(10);
	PIN_D11 = uint8(11);

	PIN_D12 = uint8(12);
	PIN_D13 = uint8(13);

	PIN_A0 = uint8(14);
	PIN_A1 = uint8(15);
	PIN_A2 = uint8(16);
	PIN_A3 = uint8(17);
	PIN_A4 = uint8(18);
	PIN_A5 = uint8(19);
    MotorConfigurationSheet;
    Signals_DD;
    ConvertParam
end
%% Variant Handling
