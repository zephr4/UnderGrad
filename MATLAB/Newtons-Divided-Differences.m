% initialize the func. and x
f1 = @(x) (exp(-x.^2));
x = -3:0.01:3;

% initialize the vectors for the data sets of x and y
datx = -3:1:3;
daty = f1(datx);

P5 =  Newtons_divided_differences(x,datx,daty)

plot(x, f1(x));
hold on;
plot(x',P5);
scatter(datx, f1(datx));
hold off;

function y = Newtons_divided_differences(x,datx,daty)
    % n is the size of the 2 value in vector x
    n = size(x,2);
    % sizeDatx is the size of the 2 value in vector datx
    sizeDatx = size(datx,2);
    % initialize row vectors with all elements being 1
    y = ones(1,n);
    F = ones(1,sizeDatx);
    
    % store each value of daty into F
    for i = 1:sizeDatx
        F(i) = daty(i);
    end
    
    % divided differences
    for i = 2:sizeDatx
        F(i:sizeDatx) = (F(i:sizeDatx) - F(i-1:sizeDatx-1)) ./ (datx(i:sizeDatx) - datx(1:sizeDatx-i+1));
    end
    
    y = y * F(sizeDatx);
    
    % Newton's implementation
    for i = 1:sizeDatx-1
        y = F(sizeDatx-i) + y .* (x-datx(sizeDatx-i));
    end
    
    y = y';
end

% Newton's Divided Difference provides a much more accurate approximation of the function as the graph tends to not oscillate near the endpoints.