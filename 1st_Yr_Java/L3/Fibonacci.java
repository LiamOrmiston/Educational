/* -----------------------------------------------------------------------------
 *
 * File Name: Fibonacci.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab 
 * Description: Program will display a sequence of Fibonacci numbers 
 * 				depending on how many numbers the user wants to see.
 * Date: 9/25/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Fibonacci 
{	public static void main(String[]args)
	{	int i = 0;
		int fib3 = 0;
		int fib2 = 1;
		int fib1 = 1;
		Scanner myScan = new Scanner(System.in);
		System.out.println("How many Fibonacci numbers would you like to see?");
		i = myScan.nextInt();
		System.out.println("Here is your Fibonacci sequence");
		if (i == 0)
		{	System.out.println("");	}
		if (i == 1)
		{	System.out.println("0");	}
		if (i == 2)
		{	System.out.println("0");
			System.out.println("1");	}
		else if (i>2)
		{	System.out.println("0");
			System.out.println("1");
			System.out.println("1");
			for (int j = 3; j < i; j = j+1)
		{	fib3 = fib1 + fib2;
		System.out.println(fib3);
			fib1 = fib2;
			fib2 = fib3; }	}
	}
}
