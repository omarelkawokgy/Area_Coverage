#ifndef I_O_WRAPPER_H
#define I_O_WRAPPER_H

#ifndef MATLAB_MEX_FILE


#else
#define	digitalWrite(x, y) 
#define digitalRead(x, y)
#define analogWrite(x, y)
#define analogRead(x, y)

#endif

#endif