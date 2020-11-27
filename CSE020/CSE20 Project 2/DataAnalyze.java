import java.util.Scanner;

public class DataAnalyze {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int i = 0;
		int size = 0;
		int total = 0, total1 = 0, total2 = 0, total3 = 0;
		int count = 0, count1 = 0, count2 = 0, count3 = 0;
		int avg = 0, avg1 = 0, avg2 = 0, avg3 = 0;
		
		System.out.print("Please enter the sample size: ");
		size = input.nextInt();
		
		int[]arr = new int[size];
		int[]arr1 = new int[size];
		int[]arr2 = new int[size];
		int[]arr3 = new int[size];
		int[]arr4 = new int[size];
		
		System.out.println("Enter numbers for trial #0");
		
		for (i = 0; i < size; i++) {
			System.out.print("Enter sample #" + i + ": ");
			arr[i] = input.nextInt();
			total += arr[i];
			count++;
			avg = total / count;
		}
			
		System.out.println("Enter numbers for trial #1");
			
		for (i = 0; i < size; i++) {
			System.out.print("Enter sample #" + i + ": ");
			arr1[i] = input.nextInt();
			total1 += arr1[i];
			count1++;
			avg1 = total1 / count1;
		}
			
		System.out.println("Enter numbers for trial #2");
				
		for (i = 0; i < size; i++) {
			System.out.print("Enter sample #" + i + ": ");
			arr2[i] = input.nextInt();
			total2 += arr2[i];
			count2++;
			avg2 = total2 / count2;
		}
		System.out.println("Enter numbers for trial #3");
		
		for (i = 0; i < size; i++) {
			System.out.print("Enter sample #" + i + ": ");
			arr3[i] = input.nextInt();
			total3 += arr3[i];
			count3++;
			avg3 = total3 / count3;
		}
		
		System.out.println("\tSample #" + "\tTrial 1" + "\t\tTrial 2" + "\t\tTrial 3" + "\t\tTrial 4");
		
		for (i = 0; i < size; i++)
			System.out.println("\t" + i + "\t\t" + arr[i] + "\t\t" + arr1[i] + "\t\t" + arr2[i] + "\t\t" + arr3[i]);
		
		System.out.println("\t-----------------------------------------------------------------------");
		
		System.out.println("Average:" + "\t\t" + avg + "\t\t" + avg1 + "\t\t" + avg2 + "\t\t" + avg3);
		
		int[] Aarr = {avg, avg1, avg2, avg3};
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		
		for (i = 0; i < Aarr.length; i++) {
			if (Aarr[i] < min)
				min = Aarr[i]; 
			if (Aarr[i] > max)
				max = Aarr[i];
		}
		
		System.out.println("Min Average: " + min);
		System.out.println("Max Average: " + max);
		
		if (min == max)
			System.out.println("The trials match EXACTLY!");
		else if (max < (2 * min))
			System.out.println("The trials concur with each other!");
		else
			System.out.println("The trials do NOT concur!");		
	}

}
