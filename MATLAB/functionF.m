f = @(x) ((x - 1).^2);

x1 = [0:0.25:1];
x2 = [0:0.01:1];

plot(f(x1))
hold on
plot(f(x2))
hold off