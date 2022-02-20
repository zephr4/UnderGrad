format rational

A = [1 1;1 3; 1 4; 1 5; 1 7]
b = [2;0;-1;3;4;]

xhat = inv(A'*A)*A'*b
fit = xhat(1) + xhat(2)*A(:,2);

scatter(A(:,2),b,100,'filled')
hold on
plot(A(:,2),fit,'LineWidth',2)
hold off
set(gca,'FontSize',14)
xlabel('x','FontSize',12)
ylabel('y','FontSize',12)
title('Best-fit line','FontSize',12)
legend({'data points','y = 7/3 + (3/4)*x '},'Location','northwest','FontSize',12)