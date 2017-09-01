/* -----------------------------------------------------------------------------
 *
 * File Name: Pyramid.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab03
 * Description: Program will print a pyramid of asterisks with a base 
 * of the user choice.
 * Date: 10/01/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Pyramid 
{	public static void main(String[]args)
	{int number = 0;
	Scanner myScan = new Scanner(System.in);
	System.out.print("Enter the number of asterisks for the base of the triangle: ");
	number = myScan.nextInt();
	for (int i=0; i<number; i++)
	{ for (int j=0; j<i; j++)
		{	System.out.print("*");	}
	System.out.println("*");	}
	}
	

}
