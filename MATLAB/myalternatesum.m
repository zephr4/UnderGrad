function finalValue = myalternatesum(x)

    finalValue = 0;
    for n = 1:x
        value = (-1)^n * n;
        finalValue = finalValue + value;
    end
end