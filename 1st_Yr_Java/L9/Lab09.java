/* -----------------------------------------------------------------------------
 *
 * File Name: Lab09.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab9
 * Description: User picks the size of 2 dimensional array then enters in all values
 * and the program will display the array and give each row's sum and average, the array's 
 * largest value, the sum for the entire array, and the entire array's average, and also transposes 
 * the array values.
 * Date: 11/12/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Lab09 
{
	public static void main(String[]args)
	{
		ArrayHelper a1 = new ArrayHelper();
		int rows = 0;
		int columns = 0;
		Scanner myScan = new Scanner(System.in);
		System.out.print("How many rows?: ");
		rows = myScan.nextInt();
		System.out.print("How many columns?: ");
		columns = myScan.nextInt();
		int [][] Array = new int [rows][columns];
		for (int i = 0; i < Array.length; i++)
		{
			for (int j = 0; j < Array[i].length; j++)
			{
				System.out.print("Enter a value for position ("+i+","+j+"): ");
				Array[i][j] = myScan.nextInt();
			}
		}
		System.out.println("Here is your array:");
		a1.print2DArray(Array);
		for (int i = 0; i < Array.length; i++)
		{
			System.out.println("row "+i+" sum= "+a1.arraySum(Array[i])+", avg = "+a1.arrayAvg(Array[i]));
		}
		System.out.println("The largest value in the array is = "+a1.arrayMax2D(Array));
		System.out.println("The sum for the entire array is = "+a1.arraySum2D(Array));
		System.out.println("The average for the entire array is = "+a1.arrayAvg2D(Array));
		if (rows == columns)
		{
			System.out.println("Here is your array transposed:");
			Array = a1.transpose(Array);
			a1.print2DArray(Array);
		}
		else
		{
			System.out.println("Cannot transpose this array");
		}
	}
}
