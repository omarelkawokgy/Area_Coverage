CAL_SimInduct_H = 0.0008; 
CAL_flux_e = 0.5;
CAL_flux_t = CAL_flux_e;
CAL_Inertia_J = 0.008;
CAL_Re_ohm = 1.5;%0.6569;%0.5;
CAL_B_NmPerW = 0.01;
CAL_CurrentScaling_A = 0.04;%1/48.9;
CONST_MinDivision = 0.00001;
CAL_PulseConstPeriod = 98*2;
CAL_DiscretDistScaling = 0.865934;

S2 = 1;
S1 = ((CAL_B_NmPerW / CAL_Inertia_J) + (CAL_Re_ohm / CAL_SimInduct_H));
S0 = (( (CAL_B_NmPerW * CAL_Re_ohm) / (CAL_Inertia_J * CAL_SimInduct_H) ) +...
    (CAL_flux_t^2 / (CAL_Inertia_J * CAL_SimInduct_H)));
Snom = (CAL_flux_t / (CAL_Inertia_J * CAL_SimInduct_H));

%sRoots = roots([S2 S1 S0]);

Z2 = (4 / CAL_SAMPLE_TIME^2) + ((S1 * 2) / CAL_SAMPLE_TIME) + S0;
Z1 = (-8 / CAL_SAMPLE_TIME^2) + 2 * S0;
Z0 = (4 / CAL_SAMPLE_TIME^2) - ((2 * S1) / CAL_SAMPLE_TIME) + S0;
Znom = Snom;
Znom2 = 2*Znom;