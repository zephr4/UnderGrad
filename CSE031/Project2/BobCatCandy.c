#include <stdio.h>

int newBars(int numBars, int wrapper){

	if (numBars % wrapper == 0){
		int bars = numBars / wrapper;
		return bars + newBars(bars, wrapper);
	}
	else
		return 0;
}

int maxBars(int price, int wrapper, int money){

	int numBars = money / price;

	if (numBars >= wrapper){
		return numBars + newBars(numBars, wrapper);
	}
}

int main() {
	
	int price, wrapper, money;
	
	price = 2;
	wrapper = 2;
	money = 16;

	printf("Enter the price for each Bobcat Bar: ");
	printf("%d\n", price);

	printf("Enter the amount of wrappers need to exchange for a single Bobcat Bar: ");
	printf("%d\n", wrapper);
	
	printf("Enter the amount of money you have: ");
	printf("%d\n", money);
    
	printf("The max number of bars is: %d\n", maxBars(price, wrapper, money) );

	return 0;
}