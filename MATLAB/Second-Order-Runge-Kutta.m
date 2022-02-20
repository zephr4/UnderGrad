f = @(t,y) -12*y;
alpha = 1;
a = 0;
b = 1;

N = 20;
[y0,t,Err0] = RK2(f,a,b,alpha,N)

N = 50;
[y1,t,Err1] = RK2(f,a,b,alpha,N)

N = 100;
[y2,t,Err2] = RK2(f,a,b,alpha,N)

Err = zeros(1,3);
Err(1) = Err0;
Err(2) = Err1;
Err(3) = Err2;

% Recieved Help from classmate: Brandon Gonzales
x0 = (b-a)/20;
x1 = (b-a)/50;
x2 = (b-a)/100;

t0 = a:x0:b;
t1 = a:x1:b;
t2 = a:x2:b;

t0 = t0';
t1 = t1';
t2 = t2';

plot(t0,y0,t1,y1,t2,y2);
loglog(Err0);

function [y,t,Err] = RK2(f,a,b,alpha,N)
    h = (b-a)/N;
    t = zeros(N,1);
    y = zeros(N,1);
    %Err = zeros(N,1);
    t(1) = a;
    y(1) = alpha;
    for i = 1:N
        t(i+1) = a + (i)*h;
        y(i+1) = y(i) + h*(f(t(i)+(h/2),y(i)+(h/2)*f(t(i),y(i))));
        if t(i+1) == 1
            Err = abs(exp(-12*t(i+1)) - y(i+1));      %need to change to fit my function
        end
    end
end

%%
%   Yes, the method converges to 0.
%%