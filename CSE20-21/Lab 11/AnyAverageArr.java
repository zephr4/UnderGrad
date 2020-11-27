import java.util.Scanner;

public class AnyAverageArr {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("This program will find the average of any numbers.");
		System.out.print("Please choose the amount of number to average: ");
		
		int max = input.nextInt();
		int i = 0;
		int arr[] = new int[max];
		int total = 0;
		
		for ( i = 0; i < max; i++) {
			System.out.print("Please enter " + i + " number: ");
			arr[i] = input.nextInt();
			total = total + arr[i];
	}
		
		System.out.println("The numbers being average: ");
		
		for (i = 0; i < max; i++) {
			System.out.print(arr[i] + " ");
			if (( i+1 ) % 5 == 0)
			System.out.println();
		}
		int average = total/max;
		System.out.println("The average is: " + average);
	}

}