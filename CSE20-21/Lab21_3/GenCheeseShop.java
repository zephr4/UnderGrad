import java.util.Random;
import java.util.Scanner;
public class GenCheeseShop {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		final int MAXCHEESE = 10;
		int i = 0;
		String[] names = new String[MAXCHEESE];
		double[] prices = new double[MAXCHEESE];
		int[] amounts = new int[MAXCHEESE];
		double[] cheeseprice = new double[MAXCHEESE];
		int display = 0;
		
		if (MAXCHEESE > 0) {
		names[0] = "Dalaran Sharp";
		prices[0] = 1.25;
		}
		if (MAXCHEESE > 1) {
		names[1] = "Stormwind Brie";
		prices[1] = 10.00;
		}
		if (MAXCHEESE > 2) {
		names[2] = "Alterac Swiss";
		prices[2] = 40.00;
		}
		
 		System.out.println("We sell " + MAXCHEESE + " kinds of Cheese");
 		if (MAXCHEESE > 0)
		System.out.println(names[0] + ": $" + prices[0] + " per pound");
		if (MAXCHEESE > 1)
		System.out.println(names[1] + ": $" + prices[1] + " per pound");
		if (MAXCHEESE > 2)
		System.out.println(names[2] + ": $" + prices[2] + " per pound");
		
 		if (MAXCHEESE > 3) {
 		Random ranGen = new Random(100);
		for (i = 3; i < MAXCHEESE; i++) {
			names[i] = "Cheese Type " + (char)('A' + i);
			prices[i] = ranGen.nextInt(1000)/100.0;
			System.out.println(names[i] + ": $" + prices[i] + " per pound");
		}
 		}
		if (MAXCHEESE > 0) {
		System.out.print("Enter the amount of " + names[0] + ":");
		amounts[0] = input.nextInt();
		cheeseprice[0] = (prices[0] * amounts[0]);
		}
		if (MAXCHEESE > 1) {
		System.out.print("Enter the amount of " + names[1] + ":");
		amounts[1] = input.nextInt();
		cheeseprice[1] = (prices[1] * amounts[1]);
		}
		if (MAXCHEESE > 2) {
		System.out.print("Enter the amount of " + names[2] + ":");
		amounts[2] = input.nextInt();
		cheeseprice[2] = (prices[2] * amounts[2]);
		}
		
		for (i = 3; i < MAXCHEESE; i++) {
			names[i] = "Cheese Type " + (char)('A' + i);
			System.out.print("Enter the amount of " + names[i] + ":");
			amounts[i] = input.nextInt();
			cheeseprice[i] = (prices[i] * amounts[i]);
	}
		if (MAXCHEESE >= 1) {
		System.out.print("Display the itemized list? (1 for yes) ");
		display = input.nextInt();
		}
		
		if (display == 1) {
		for(i= 0; i < MAXCHEESE; i++) 
			if (amounts[i] > 0)
				System.out.println(amounts[i] + " lbs of " + names[i] + " $" + prices[i] + " = $" + cheeseprice[i]);
		}
		else 
			System.out.print("");
		
		double subtotals = 0;
		for (i = 0; i < MAXCHEESE; i++) {
		subtotals += cheeseprice[i];
		}
		System.out.println("Sub Total : $" + subtotals);
		
		int discount;
		if (subtotals > 100) {
			System.out.println("-Discount: $" + 25.0);
			discount = 25;
		}
		else if (subtotals > 50) {
			System.out.println("-Discount: $" + 10.0);
			discount = 10;
		}
		else {
			System.out.println("-Discount: $0.0");
		discount = 0;
		}
		
		double total = subtotals - discount;
		System.out.print("Total: $" + total);
	}
	}