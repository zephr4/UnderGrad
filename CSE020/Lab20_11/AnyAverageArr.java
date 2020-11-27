import java.util.Scanner;

public class AnyAverageArr {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Please enter the amount of number you wish to average: ");
		int max = input.nextInt();
		
		int[]arr = new int[max];
		int i = 1;
		int total = 0;
		int count = 0;
		
		System.out.println("The numbers being averaged: ");
		for (i = 0; i < max; i++) {
			System.out.println("Please enter " + i + " number: " + arr[i]);
			arr[i] = input.nextInt();
			total += arr[i];
			count++;
		}
		
		
		for (i = 0; i < max; i++) {
			System.out.print(arr[i] + " ");
			if ((i + 1) % 5 == 0)
			System.out.println();	
		}
		System.out.println();
		System.out.println("The average is: " + total / count);
	}

}
