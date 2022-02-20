format long
f = @(x) ((2*x.^3 + 3*x - 1).*cos(x) - x)
plot([-1:0.1:1], f(-1:0.1:1))
[c,n,err] = bisection_method(f, -1, 1, 10^-5, 1000)

function [c,n,err] = bisection_method(f,a,b,tol,N)

    n = 0;
    c = (a + b) / 2;
    
    if f(a) * f(b) < 0
        
        err = (b - a) / 2;
        
        while err > tol && n < N
            
        
            
            if f(a) * f(c) < 0
                b = c;
            else
                a = c;
            end
            
            err = (b - a) / 2;
            c = (a + b) / 2;
            n = n + 1;
        end
    end
end  