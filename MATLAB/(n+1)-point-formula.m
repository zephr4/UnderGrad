format long 

f = @(x) ((x^2 - 3*x + 2) .* atan(x));
forward_Diff = @(x, h) ((f(x + h) - f(x)) ./ h);
Three_point_Diff = @(x, h) ((f(x + h) - f(x - h)) ./ (2*h));
Five_point_Diff = @(x, h) ((-f(x + 2*h) + (8*f(x + h)) - (8*f(x - h)) + f(x - 2*h)) ./ (12*h));
h = @(n) (10^(-n));

n = 1;
x = 0;

[FD1, FD3, FD6] = Forward_Difference(f, forward_Diff, h, n, x)
[CD31, CD33, CD36] = Three_Point_Centered_Difference(f, Three_point_Diff, h, n, x)
[CD51, CD53, CD56] = Five_Point_Centered_Difference(f, Five_point_Diff, h, n, x)

err1 = abs([FD1, FD3, FD6] - 2);
err2 = abs([CD31, CD33, CD36] - 2);  
err3 = abs([CD51, CD53, CD56] - 2);

loglog([1, 3, 6], err1)
hold on
loglog([1, 3, 6], err2)
hold on
loglog([1, 3, 6], err3)
hold off

function [a1, a2, a3] = Forward_Difference(f, forward_Diff, h, n, x)
    
    while (n <= 6)
        
        if (n == 1)
            a1 = forward_Diff(x, h(n));
            n = 3;
        elseif (n == 3)
            a2 = forward_Diff(x, h(n));
            n = 6;
        else
            a3 = forward_Diff(x, h(n));
            n = 100;
        end       
    end
end

function [a1, a2, a3] = Three_Point_Centered_Difference(f, Three_Point_Diff, h, n, x)
    
    while (n <= 6)
        
        if (n == 1)
            a1 = Three_Point_Diff(x, h(n));
            n = 3;
        elseif (n == 3)
            a2 = Three_Point_Diff(x, h(n));
            n = 6;
        else
            a3 = Three_Point_Diff(x, h(n));
            n = 100;
        end        
    end
end

function [a1, a2, a3] = Five_Point_Centered_Difference(f, Five_Point_Diff, h, n, x)
    
    while (n <= 6)
        
        if (n == 1)
            a1 = Five_Point_Diff(x, h(n));
            n = 3;
        elseif (n == 3)
            a2 = Five_Point_Diff(x, h(n));
            n = 6;
        else
            a3 = Five_Point_Diff(x, h(n));
            n = 100;
        end
    end
end
    