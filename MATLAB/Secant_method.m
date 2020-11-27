function root = Secant_method(f, x0, x1, tol, N)
    
    i = 2;
    y0 = f(x0);
    y1 = f(x1);
    
    while i <= N
        
        root = x1 - y1 * (x1 - x0) / (y1 - y0);
        
        if abs(root - x1) < tol
            break
        end
        
        if abs(root - x1) >= tol && i >= N 
            disp('The method failed after N iterations: N = ')
            disp(N)
        end
        
        i = i + 1;
        x0 = x1;
        x1 = root;
        y0 = y1;
        y1 = f(root);
    end
    
    if abs(root - x1) >= tol
        disp('The method failed after N iterations: N = ')
        disp(N)
    end
    
end