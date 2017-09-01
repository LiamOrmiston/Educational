/* -----------------------------------------------------------------------------
 *
 * File Name: Prime.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Homework2
 * Description: User enters in a number and the program tells the user 
 * whether the number is prime or not.
 * Date: 10/05/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Prime 
{
	public static void main(String[]args)
	{
		int choice = 0;
		int result = 0;
		int i = 2;
		Scanner myScan = new Scanner(System.in);
		System.out.print("Input a positive integer: ");
		choice = myScan.nextInt();
		if (choice < 1)
		{
			System.out.print("Error: Input a positive integer");
		}
		else if (choice == 1)
		{
			System.out.println("Not prime, but worth talking to a Professor of Maths about.");
		}
		else
		{
		while (choice % i != 0 && i < choice-1)
		{
			i++;
		}
		if (choice % i == 0)
		{
			System.out.println(choice+" is not prime");
		}
		if (choice % i != 0)
		{
			System.out.println(choice+" is prime");
		}
		}
	}

}
