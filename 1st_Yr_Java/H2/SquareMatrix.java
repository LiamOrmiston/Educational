/* -----------------------------------------------------------------------------
 *
 * File Name: SquareMatrix.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Homework2
 * Description: User will pick the size of a matrix and the program will display
 * a square matrix and its transposed counterpart.
 * Date: 10/04/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class SquareMatrix 
{	public static void main(String[]args)
{
	int choice = 0;
	Scanner myScan = new Scanner(System.in);
	System.out.println("Enter the Size of the Square Matrix:");
	choice = myScan.nextInt();
	System.out.println("Square Matrix:");
	for (int i = 0; i < choice; i++)
	{
		if (i > 0)
		{
			for (int x = 1; x <= choice; x++)
			{
				System.out.print((choice*i + x)+" ");
			}
		}
		else
		{
		for (int j = 0; j< choice; j++)
		{

			System.out.print((j+1)+" ");
		}
		}
		System.out.println("");
	}
	System.out.println("Transpose:");
	for (int i = 1; i <= choice; i++)
	{
		for (int j = 0; j< choice; j++)
		{
			if (j > 0)
			{
				System.out.print((i + choice*j)+" ");
			}
			else
			{
				System.out.print((i)+" ");
			}
		}
		System.out.println("");
		}

	}
}

