format long

y = @(x) (x); 
g = @(x) (exp(-x));
plot([-1:0.1:1], g(-1:0.1:1), [-1:0.1:1], y(-1:0.1:1))
x0 = -1;
tol = 10^-10;
N = 100;

g1 = @(x) (1 ./ (1 + x));
x01 = -1;
N1 = 100;

[c,n,err] = fixed_point_iteration(g,x0,tol,N)
[c1,n1,err1] = fixed_point_iteration(g1,x01,tol,N1)

function [c,n,err] = fixed_point_iteration(g,x0,tol,N)
    
    n = 0;
    c = x0;
    previousX = x0;
    err = Inf;
    
    while (err >= tol) & (n <= N)
        
        c = g(c);
        err = abs(c - previousX);
        previousX = c;
        n = n + 1;
    end
end