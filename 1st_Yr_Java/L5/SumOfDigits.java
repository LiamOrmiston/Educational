/* -----------------------------------------------------------------------------
 *
 * File Name: SumOfDigits.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab5
 * Description: Program adds the digits together and asks if the user wants to run
 * the program again.
 * Date: 10/08/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class SumOfDigits 
{
	public static void main(String[]args)
	{
		int choice = 0;
		int sum = 0;
		int again = 0;
		Scanner myScan = new Scanner(System.in);
		System.out.println("Please enter a No: ");
		choice = myScan.nextInt();
		sum = addDigits(choice);
		System.out.println("The sum of the digits is: "+sum);
		System.out.println("");
		System.out.println("Want to try again?(y=1/n=0):");
		again = myScan.nextInt();
		System.out.println("");
		while (again == 1)
		{
			System.out.println("Please enter a No: ");
			choice = myScan.nextInt();
			sum = addDigits(choice);
			System.out.println("The sum of the digits is: "+sum);
			System.out.println("");
			System.out.println("Want to try again?(y=1/n=0):");
			again = myScan.nextInt();
			System.out.println("");	
		}
		if (again == 0)
		{
			System.out.println("Thank you!");
		}
	}
	public static int addDigits(int x)
	{
		int i = 0;
		int j = 0;
		while (i != x)
		{
			i = x % 10;
			j = i + j;
			x = x/10;
		}
		return(j);
	}
}
