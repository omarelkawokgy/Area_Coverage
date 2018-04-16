function myFunc(block, x, y)
plot(x, y)

function setup(block)


function CheckPrms(block)
  mu = block.DialogPrm(1).Data;
  
  if mu <= 0 || mu > 1
    error(message('simdemos:adapt_lms:stepSize'));
  end

function start(block)


function Outputs(block)
  
  mu = block.RuntimePrm(1).Data;
  N  = 32;
  
  u = block.InputPort(2).Data;
  d = block.InputPort(1).Data;
  
  X = block.Dwork(1).Data;
  H = block.Dwork(2).Data;
  
  %%
  %% H^(n+1)[i] = H^(n)[i]+mu*(d(n)-y(n))*u(n-i) 
  %% 
  X(2:N) = X(1:N-1);
  X(1)   = u;  
  y      = X'*H;  
  e      = d-y;  
  H      = H+mu*e*X;

  block.Dwork(1).Data = X;
  block.Dwork(2).Data = H;
  block.OutputPort(1).Data = y;

  %% Outputs the difference between the estimated filter coefficients
  %% and the actual coefficients.
  b = evalin('base','b'); %% b is the actual filter coefficients
  block.OutputPort(2).Data = norm(b'-H);
  
%endfunction