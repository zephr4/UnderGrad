f = @(t,y) (sin(2*t) - 2*t*y) / (t^2);
alpha = 2;
a = 1;
b = 5;

N = 10;
[y0,t] = euler_method(f,a,b,alpha,N)

N = 10^2;
[y1,t] = euler_method(f,a,b,alpha,N)

N = 10^3;
[y2,t] = euler_method(f,a,b,alpha,N)

% Recieved Help from classmate: Brandon Gonzales
x0 = (b-a)/10;
x1 = (b-a)/100;
x2 = (b-a)/1000;

t0 = a:x0:b;
t1 = a:x1:b;
t2 = a:x2:b;

t0 = t0';
t1 = t1';
t2 = t2';

plot(t0,y0,t1,y1,t2,y2);
Err0 = 1;
loglog(Err0);

function [y,t] = euler_method(f,a,b,alpha,N)
    h = (b-a)/N;
    t = zeros(N,1);
    y = zeros(N,1);
    y(1) = alpha;
    for i = 1:N
        t(i) = a + (i-1)*h;
        y(i+1) = y(i) + h*f(t(i),y(i));
        %if t(i) == 5
           % Err = abs((-cos(2*t(i))+4.412)/(2*t^2) - y(i+1));
       %end
    end
end

%%
%       The method works best with y2 and works worst with y1. This is because the accuracy of the mthod is dependent on the # of iterations.      
%%