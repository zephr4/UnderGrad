format long

f = @(x) (atan(x) - 1);
fp = @(x) (1 / (x.^2 + 1));
x0 = 2;                         %%%%% if the initial guess in x0 = -2, Newton's Method does not converge to root. 
tol = 10^-8;
N = 100;

plot([-4:0.1:4], f(-4:0.1:4))
[c,n,err] = Newtons_method(f,fp,x0,tol,N)

function [c,n,err] = Newtons_method(f,fp,x0,tol,N)
    
    n = 0;
    c = x0;
    previousX = x0;
    err = Inf;
    
    while n < N
        
        c = c - (f(c) / fp(c));
        err = abs(c - previousX);
        
        if (err <= tol)
            break
        end
        
        previousX = c;
        n = n + 1;
    end
end