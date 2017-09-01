/* -----------------------------------------------------------------------------
 *
 * File Name: Factorial.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab03 
 * Description: Program calculates the factorial of the number the user enters.
 * Date: 10/02/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Factorial 
{	public static void main(String[]args)
	{int factorial = 1;
	int output = 1;
	int j = 1;
	Scanner myScan = new Scanner(System.in);
	System.out.print("Enter the number to compute factorial ");
	j = myScan.nextInt();
	while (j<0)
		{System.out.print("Please enter a non-negative number ");
		j = myScan.nextInt();	}
	System.out.print("Result for "+j+"! = ");
	for (int i = 1; i <= j; i++)
		{System.out.print(j+1-i);
		if (i != j)
		{ System.out.print("*");	}
		factorial = factorial*i;	}
	System.out.println(" = "+factorial);
	
	}

}
