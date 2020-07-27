Vr = 10;
Vl = 10;
L = 2;

X = 11;
Y = 11;
theta = 30;

dX = 0;
dY = 0;
dtheta = 0;
dT = 0.1;

W = (Vr - Vl)/L;

if (Vr - Vl) == 0
    R = inf;
else
    R = (L/2)*((Vr + Vl)/(Vr - Vl));
end

plot(X, Y, 'or', 'MarkerSize', 30);

lineLength = 20;

while(1)
ICCx = X - R*sind(theta);
ICCy = Y + R*cosd(theta);
if (Vr - Vl) == 0
    dX = X + cosd(theta)*(Vr*dT);
    dY = Y + sind(theta)*(Vr*dT);
else
    dX = cosd(W*dT)*(X - ICCx) + (-sind(W*dT) * (Y - ICCy)) + ICCx;
    dY = sind(W*dT)*(X - ICCx) + (cosd(W*dT) * (Y - ICCy)) + ICCy;
end
dtheta = theta + W*dT;

X = dX;
Y = dY;
theta = dtheta;
    
if theta > 360
    theta = theta - 360;
end
plot(X, Y, 'or', 'MarkerSize', 30);
hold on
%theta = 30;
robotLocation = X; 
op = sind(theta) * lineLength;
adj = cosd(theta) * lineLength;
yend = Y + op;
xend = X + adj;
start = [X xend];
finish = [Y yend];
plot(start, finish, 'LineWidth', 3)
hold off;
xlim([0 200]);
ylim([0 200]);
grid on
grid minor
pause(0.5);
end
