function [c,n,err] = Newtons_method(f,fp,x0,tol,N)
    
    n = 0;
    c = x0;
    previousX = x0;
    err = Inf;
    
    while n < N
        
        c = c - (f(c) / fp(c));
        err = abs(c - previousX);
        
        if err < tol
            break
        end
        
        previousX = c;
        n = n + 1;
    end
end