function [c,n,err] = fixed_point_iteration(g,x0,tol,N)
    
    n = 0;
    c = x0;
    previousX = x0;
    err = Inf;
    
    while (err >= tol) & (n < N)
        
        c = g(c);
        err = abs(c - previousX);
        previousX = c;
        n = n + 1;
    end
end