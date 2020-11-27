import java.util.Scanner;
public class CheeseShop {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		double sharpprice=1.25;
		double brieprice=10.00;
		double swissprice=40.00;
				
		System.out.println("We sell 3 kinds of Cheese");
		System.out.println("Dalaran Sharp: $1.25 per pound");
		System.out.println("Stormwind Brie: $10.00 per pound");
		System.out.println("Alterac Swiss: $40.00 per pound");
		
		int sharplbs;
		System.out.print("Enter the amount of Sharp in lbs: ");
		sharplbs = input.nextInt();
		double sharpfinal = (sharpprice * sharplbs);
		
		int brielbs;
		System.out.print("Enter the amount of Brie in lbs: ");
		brielbs = input.nextInt();
		double briefinal = (brieprice * brielbs);
		
		int swisslbs;
		System.out.print("Enter the amount of Swiss in lbs: ");
		swisslbs = input.nextInt();
		double swissfinal = (swissprice * swisslbs);
		
		double subtotal = (sharpfinal + briefinal + swissfinal);
		
		System.out.print("Display the itemized list? (1 for yes) ");
		int display = input.nextInt();
		
		if (display == 1 && sharplbs > 0) 
			System.out.println(sharplbs + " lbs of Sharp @ $1.25 = $" + sharpfinal);
		if (display == 1 && brielbs > 0) 
			System.out.println(brielbs + " lbs of Brie @ $10.00 = $" + briefinal);
		if (display == 1 && swisslbs > 0) 
			System.out.println(swisslbs + " lbs of Swiss @ $40.00 = $" + swissfinal);
		
		System.out.println("Sub Total: $" + subtotal);
		
		int discount;
		if (subtotal > 100) {
			System.out.println("-Discount: $" + 25.0);
			discount = 25;
		}
		else if (subtotal > 50) {
			System.out.println("-Discount: $" + 10.0);
			discount = 10;
		}
		else {
			System.out.println("-Discount: $0.0");
		discount = 0;
		}
		double total = subtotal - discount;
		System.out.print("Total: $" + total);
	}
}