f1 = @(x) (exp(-x.^2));
f2 = @(x) (1./(1+x.^2));
x = -3:0.01:3;

datx = -3:1:3;
datx1 = -3:0.5:3;

daty = f1(datx);
daty_2 = f2(datx);
daty1 = f1(datx1);
daty1_2 = f2(datx1);

P1 = Lagrange_poly(x,datx,daty)
P2 = Lagrange_poly(x,datx,daty_2)
P3 = Lagrange_poly(x,datx1,daty1)
P4 = Lagrange_poly(x,datx1,daty1_2)

plot(x, f1(x), x, f2(x));
hold on;
plot(x', P1, x', P2);
scatter(datx, f1(datx));
scatter(datx, f2(datx));

plot(x, f1(x), x, f2(x));
plot(x', P3, x', P4);
scatter(datx, f1(datx));
scatter(datx, f2(datx));
hold off;

function y = Lagrange_poly(x,datx,daty)
    % datx is a vector of x values 
    % daty is a vector of y values
    % x is point we evauated using this Lagrange interpolation polynomial
    % The result is a constant.
    
    y = 0;
    n = size(x, 2);
    size_datx = size(datx, 2);
    product = ones(size_datx, n);   % The product variable, aka the L term in the formula
    
    for i = 1 : size_datx     
        for j = 1 : size_datx
            if i ~= j   % if j does not equal i
                product(i,:) = product(i,:) .* (x - datx(j)) / (datx(i) - datx(j));
            end 
        end
    end
    for i = 1 : size_datx
        y = y + daty(i) * product(i,:);
    end
    y = y';
end
