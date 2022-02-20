f = @(t) (cos((pi * t^2) / 2));

a = 0;
b = pi;
n1 = 10^3;
n2 = 10^5;

I3 = composite_simpsons(f,a,b,n1)
I4 = composite_simpsons(f,a,b,n2)

actual = fresnelc(pi);
err1 = actual - I3;
err2 = actual - I4;
loglog(I3, err1)
hold on
loglog(I4, err2)
hold off

function I = composite_simpsons(f,a,b,n)
    h = (b-a)/n;
    sI0 = f(a) + f(b);
    sI1 = 0; sI2 = 0;
    % odd terms
    for i = 1:n-1
        x = a + i*h;
        if mod(i,2) == 0
            sI2 = sI2 + f(x);
        else
            sI1 = sI1 + f(x);
        end 
    end
    
    I = (h/3)*(sI0 + 2*sI2 + 4*sI1); 
end