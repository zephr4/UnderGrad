f = @(t,y) -12*y;
alpha = 1;
a = 0;
b = 1;

N = 20;
[y6,t,Err6] = AB4(f,a,b,alpha,N)

N = 50;
[y7,t,Err7] = AB4(f,a,b,alpha,N)

N = 100;
[y8,t,Err8] = AB4(f,a,b,alpha,N)

Err2 = zeros(1,3);
Err2(1) = Err6;
Err2(2) = Err7;
Err2(3) = Err8;

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

plot(t0,y6,t1,y7,t2,y8);
loglog(Err6);

function [y,t,Err] = AB4(f,a,b,alpha,N)
   %function that computes solve the IVP using four step Adams-Bashforth method
    %INPUTS: 
    %function f
    %initial condition alpha
    %bounds of interval [a,b]
    %N number of nodes used
    %yinit: first 4 values of the soltuion
    %OUTPUT: 
    %y the solution
    %t the time sequence
    
    %creation of the nodes and time step
    t = zeros(N+1,1);
    h = (b-a)/(N);
    for i = 1:N+1
        t(i) = a + (i-1) *h;
    end
    
    %creation solution via AB4 method
    y = zeros(N+1,1);
    y(1) = alpha;
    %use RK4 for the first steps
    for i = 2:4
        k1 = h* f(t(i-1),y(i-1));
        k2 = h * f(t(i-1) + (1/2)*h, y(i-1) + (1/2)*k1);
        k3 = h * f(t(i-1) + (1/2)*h, y(i-1) + (1/2)*k2);
        k4 = h * f(t(i), y(i-1) + k3);
        y(i) = y(i-1) + (k1 + 2*k2 + 2*k3 +k4)/6;
    end
    %use AB4 for the rest
    for i = 5:N+1
        y(i) = y(i-1) + h/24 * ( 55 * f(t(i-1), y(i-1)) ...
            -59 * f(t(i-2), y(i-2)) + 37 * f(t(i-3), y(i-3)) ...
            - 9 * f(t(i-4), y(i-4)) );
        
        if i == N+1
            Err = abs(exp(-12*t(i)) - y(i));
        end
    end
end

%%
%   This method converges for N = 50,100, but not for N = 20.
%%