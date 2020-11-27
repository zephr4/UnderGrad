import java.util.Scanner;

public class BobcatCar {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int car;
		
		System.out.println("Available cars: 1 for Economy, 2 for Compact, 3 for Standard");
		System.out.println("Please choose the rental car: ");
		car = input.nextInt();
		
		int cost;
		if (car == 1) 
			cost = 35;
		else if (car == 2)
			cost = 45;
		else
			cost = 95;
		
		
		int days;
		System.out.println("Please enter the number of rental days: ");
		days = input.nextInt();
		
		
		int member;
		System.out.println("Club Member?: 1 for yes, 0 for no: ");
		member = input.nextInt();
		
		int platinum = 0;
		if (member == 1) {
			System.out.println("Platinum Executive Package?: 1 for yes, 0 for no: ");
			platinum = input.nextInt();
		}
		
		
		System.out.println();
		
		int basePrice = days * cost;
		if (car == 1)
			System.out.println("Base: " + days + " days for an Economy @ $35 per day is $ " + basePrice);
		else if (car == 2)
			System.out.println("Base: " + days + " days for a Compact @ $45 per day is $ " + basePrice);
		else
			System.out.println("Base: " + days + " days for a Standard @ $95 per day is $ " + basePrice);
		

		int MemberDiscount = (days/7) * cost;
		if (member == 1 && car >= 1) {
			System.out.println("Club Member Discount: - $ " + MemberDiscount);
		}
		else 
			System.out.println("Club Member Discount: - $ 0");
		
		double platinumPrice = (double)(basePrice * 0.15);
		if (platinum == 1) 
			System.out.println("Platinum Executive Package: + $ " + platinumPrice);
		
		
		System.out.println();
		
		if (car >= 1 && member == 1 && platinum == 1)
			System.out.println("Total Estimate for Rental: $ " + (basePrice - MemberDiscount + platinumPrice));
		else if (car >= 1 && member == 1 && platinum == 0)
			System.out.println("Total Estimate for Rental: $ " + (basePrice - MemberDiscount));
		else 
			System.out.println("Total Estimate for Rental: $ " + basePrice);
			
		
		
		
	

	}

}
