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
%AreaCoverageCalib;
MotorConfigurationSheet;
%Test_MotorConfigurationSheet;
Signals_DD
% ConvertParam

% 
% Znom = Snom.Value;
% Znom2 = 2*Znom;
% 
% Z2 = (4 / (CAL_SAMPLE_TIME.Value)^2) + ((S1.Value * 2) / (CAL_SAMPLE_TIME.Value)) + S0.Value;
% Z1 = (-8 / (CAL_SAMPLE_TIME.Value)^2) + 2 * S0.Value;
% Z0 = (4 / (CAL_SAMPLE_TIME.Value)^2) - ((2 * S1.Value) / (CAL_SAMPLE_TIME.Value)) + S0.Value;
% 
% ENU_DIAG_COMP = uint8(1);
% ENU_DIAG_ENCOD = uint8(2);
% ENU_DIAG_BLTOTH = uint8(5);
% ENU_DIAG_ANGLE_CALIB = uint8(6);