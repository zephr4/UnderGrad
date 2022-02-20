f = @(t) (cos((pi * t^2) / 2));

a = 0;
b = pi;
n1 = 10^3;
n2 = 10^5;

I1 = composite_trapezoid(f,a,b,n1)
I2 = composite_trapezoid(f,a,b,n2)

actual = fresnelc(pi);
err1 = actual - I1;
err2 = actual - I2;

loglog(I1, err1)
hold on
loglog(I2, err2)
hold off

function I = composite_trapezoid(f,a,b,n)
    % subinterval width/step size/mesh size
    h = (b-a)/n;

    % initial value of the sum
    I = f(a)+ f(b);

    for i = 1:(n-1)
        I = I + 2*f(a+i*h);
    end
    
    I = (h/2)*I;
end