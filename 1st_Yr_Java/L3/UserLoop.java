/* -----------------------------------------------------------------------------
 *
 * File Name: Userloop.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab 
 * Description: Program will display a list of numbers depending on the starting and ending point the user gives
 * Date: 9/24/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class UserLoop 
{
	public static void main(String[]args)
		{	int start = 0;
			int end = 0;
			Scanner myScan = new Scanner(System.in);
			System.out.println("Input a start value (included): ");
			start = myScan.nextInt();
			System.out.println("Input an ending value (excluded): ");
			end = myScan.nextInt();
				if (start < end)
				{	while (start < end)
					{	System.out.println(start);
						start = start + 1;	}	}
				else
				{	System.out.println("Invalid input");	}
		}
}
