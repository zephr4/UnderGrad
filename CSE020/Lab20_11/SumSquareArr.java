import java.util.Scanner;

public class SumSquareArr {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Please enter the max number: ");
		int max = input.nextInt();
		
		int[]arr1 = new int[max + 1];
		int[]arr2 = new int[max + 1];
		int[]arr3 = new int[max + 1];
		arr1[0] = 0;
		arr2[0] = 0;
		arr3[0] = 0;
		
		int i = 1;
		
		for (i = 1; i <= max; i++)
			arr1[i] = arr1[i - 1] + (i * i);
		
		i = 1;
		
		while (i <= max) {
			arr2[i] = arr2[i - 1] + (i * i);
			i++;
		}
		i = 1;
		
		do 
			arr3[i] = arr3[i - 1] + (i * i);
		while (++i <= max);
		
		for (i = 0; i <= max; i++)
		System.out.println("Arr1 " + arr1[i] + " Arr2 " + arr2[i] + " Arr3 " + arr3[i]);
		
		System.out.println("Sum of all is : " + arr1[max]);
	}

}
