odd = 0
count = 0
for i in range(10):
    num = int(input("Enter a number: "))
    if (num % 2 != 0):  
        if (num > odd):
            odd = num       
    else:
        count = count + 1

if (count != 10):
    print(odd)
else:
    print("No odd number were entered.")