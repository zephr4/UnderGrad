import java.util.Scanner;


public class PosAverage {

	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		//System.out.print("Please enter the max number:");

		//int max = input.nextInt();
		int i = 0;
		int sum = 0;
		int num = 0;
		do {
			System.out.print("Enter " + i);
			System.out.print(" Number: ");
			num = input.nextInt();
			if (num <= 0)
				break;
			i++;
			sum += num;
		} while (num > 0);
		
		System.out.println("Average is " + sum/i);

	}

}
