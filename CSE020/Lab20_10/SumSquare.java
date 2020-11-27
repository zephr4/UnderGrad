import java.util.Scanner;


public class SumSquare {

	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Please enter the max number:");

		int max = input.nextInt();
		int total = 0;
		int i = 1;
	
		
		do {
			int I2 = i * i;
			System.out.println("Number " + i + " squared is " + I2);
			total = total + I2;
			i++;
		}
		
		while (i <= max);
		
		System.out.println("Sum is " + total);
			
		

	}

}
