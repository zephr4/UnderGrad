import java.util.Random;
import java.util.Scanner;

public class Shop {

	Cheese Sharp, Brie, Swiss;

	public Shop() {
		Sharp = new Cheese();
		Sharp.setName("Sharp");
		Sharp.setPrice(1.25);

		Brie = new Cheese("Brie");
		Brie.setPrice(10.00);

		Swiss = new Cheese("Swiss", 40.00);
	}

	private void intro(Scanner input) {
		System.out.println("We sell 3 types of Cheese");
		System.out.println(Sharp.getName() + ": $" + Sharp.getPrice() + " per pound");
		System.out.println(Brie.getName() + ": $" + Brie.getPrice() + " per pound");
		System.out.println(Swiss.getName() + ": $" + Swiss.getPrice() + " per pound");

		System.out.print("Enter amount of " + Sharp.getName() + " : ");
		Sharp.setAmount(input.nextInt());
		System.out.print("Enter amount of " + Brie.getName() + " : ");
		Brie.setAmount(input.nextInt());
		System.out.print("Enter amount of " + Swiss.getName() + " : ");
		Swiss.setAmount(input.nextInt());
	}

	private double calcSubTotal() {
		double subTotal = 0;
		subTotal += Sharp.getAmount() * Sharp.getPrice();
		subTotal += Brie.getAmount() * Brie.getPrice();
		subTotal += Swiss.getAmount() * Swiss.getPrice();

		return subTotal;
	}

	private double discount(double sub) {
		return ((sub > 100)? 25 : (sub > 50)? 10: 0);
	}

	private void itemizedList(){
		int amt;
		System.out.println();
		if ((amt = Sharp.getAmount()) > 0) 
			System.out.println(amt + " lbs of Dalaran Sharp  @ $1.25  = " + (amt * Sharp.getPrice()));
		if ((amt = Brie.getAmount()) > 0) 
			System.out.println(amt + " lbs of Stormwind Brie  @ $10.00  = " + (amt * Brie.getPrice()));
		if ((amt = Swiss.getAmount()) > 0) 
			System.out.println(amt + " lbs of Alterac Swiss  @ $40.00  = " + (amt * Swiss.getPrice()));
	}

	private void printTotal(double sub, double disc) {
		System.out.println();
		System.out.println("Sub Total  : $" + sub);
		System.out.println("- Discount : $"+ disc);
		System.out.println("Total Price: $" + (sub - disc));
	}
	
	private void printFree(){
		int amt;
		System.out.println();
		System.out.println("Today is your lucky day!");
		if ((amt = Sharp.getAmount()) > 0) 
			System.out.println(amt + " lbs of Dalaran Sharp  @ $0 = " + 0);
		if ((amt = Brie.getAmount()) > 0) 
			System.out.println(amt + " lbs of Stormwind Brie @ $0 = " + 0);
		if ((amt = Swiss.getAmount()) > 0) 
			System.out.println(amt + " lbs of Alterac Swiss  @ $0 = " + 0);
		System.out.println("Total Price: FREE");
	}

	public void run() {

		Scanner input = new Scanner(System.in);
		intro(input);
		double sub = calcSubTotal();
		double disAmt = discount(sub);

		System.out.println();
		System.out.print("Do you want to see the itemized list? (1 for yes): ");
		int list = input.nextInt();
		if (list == 1)
			itemizedList();	

		int free = (new Random()).nextInt(100);
		System.out.println("Random num is " + free);
		if (free != 0)
			printTotal(sub, disAmt);
		else {
			printFree();
			return;
		}
		
		System.out.println();
		System.out.print("Do you wish to redo your whole order? (1 for yes): ");
		int redo = input.nextInt();

		System.out.println();

		if (redo == 1)
			run();
		else
			System.out.println("Thanks for coming!");
	}
}
