import java.util.Scanner;

public class ReminderFunc {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Please enter the max number: ");
		int max = input.nextInt();
		
		System.out.print("Please enter the divisor: ");
		int divisor = input.nextInt();

		for(int i = 1; i <= max; i++) {
			int answer = i % divisor; 
			System.out.println("Num: " + i + " % " + divisor + " = " + answer);
		}
	}

}
