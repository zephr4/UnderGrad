f = @(t,y) -12*y;
alpha = 1;
a = 0;
b = 1;

N = 20;
[y3,t,Err3] = RK4(f,a,b,alpha,N)

N = 50;
[y4,t,Err4] = RK4(f,a,b,alpha,N)

N = 100;
[y5,t,Err5] = RK4(f,a,b,alpha,N)

Err1 = zeros(1,3);
Err1(1) = Err3;
Err1(2) = Err4;
Err1(3) = Err5;

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

plot(t0,y3,t1,y4,t2,y5);
loglog(Err3);

function [y,t,Err] = RK4(f,a,b,alpha,N)
    h = (b-a)/N;
    t = zeros(N,1);
    y = zeros(N,1);
    Err = zeros(N,1);
    t(1) = a;
    y(1) = alpha;
    for i = 1:N
        t(i+1) = a + (i)*h;
        k1 = h*f(t(i),y(i));
        k2 = h*f(t(i)+(h/2),y(i)+(1/2)*k1);
        k3 = h*f(t(i)+(h/2),y(i)+(1/2)*k2);
        k4 = h*f(t(i+1),y(i)+k3);
        y(i+1) = y(i) + (1/6)*(k1 + 2*k2 + 2*k3 + k4);
        if t(i+1) == 1
            Err = abs(exp(-12*t(i+1)) - y(i+1));
        end
    end
end

%%
%       Yes, the method converges to zero.
%%