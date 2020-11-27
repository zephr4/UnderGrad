function [c,n,err] = bisection_method(f,a,b,tol,N)

    n = 0;
    c = 0;
    
    if f(a) * f(b) < 0
        
        err = (b - a) / 2;
        
        while abs(err) > tol && n <= N
            
            c = (a + b) / 2;
            
            if f(a) * f(c) < 0
                b = c;
            else
                a = c;
            end
            
            err = (b - a) / 2;
            n = n + 1;
        end
    end
end                