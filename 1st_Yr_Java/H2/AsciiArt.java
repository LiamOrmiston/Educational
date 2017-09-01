/* -----------------------------------------------------------------------------
 *
 * File Name: AsciiArt.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Homework2
 * Description: User will pick what kind of patter he or she would like to produce
 * and then pick how many rows they would like to see of that pattern.
 * Date: 10/04/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class AsciiArt 
{	public static void main(String[]args)
	{
	int choice = 0;
	Scanner myScan = new Scanner(System.in);
	System.out.println("Choose one of the following patterns by typing the corresponding number:");
	System.out.println("1) Stripes");
	System.out.println("2) Checker Board");
	System.out.println("3) Double Diagonal (aka the X)");
	System.out.println("4) Two Islands");
	choice = myScan.nextInt();
	if (choice < 1)
	{
		System.out.println("Error.");
	}
	if (choice == 1)
	{
		int size = 0;
		System.out.println("Input a size (must be larger than 1):");
		size = myScan.nextInt();
		if (size <= 1)
		{
			System.out.println("Error.");
		}
		else
		{
		for(int i=0; i<size; i++)
		{System.out.print(i+" ");
		for (int j = 0; j < 5; j++)
		{
			if ((j)%2 == 0)
			{
				System.out.print("*");
			}
			else
			{
				System.out.print(" ");
			}
		}
		System.out.println("");
		}
		}
	}
	if (choice == 2)
	{
		int size = 0;
		System.out.println("Input a size (must be larger than 1):");
		size = myScan.nextInt();
		if (size <= 1)
		{
			System.out.println("Error.");
		}
		else
		{
		for (int i = 0; i < size; i++)
		{System.out.print(i+" ");
			for (int j = 0; j < 5; j++)
			{
				if ((i+j)%2 == 0)
				{
					System.out.print("*");
				}
				else
				{
					System.out.print(" ");
				}
			}
			System.out.println("");
		}
		}
	}
	if (choice ==3)
	{
		int size = 0;
		System.out.println("Input a size (must be larger than 1):");
		size = myScan.nextInt();
		if (size <= 1)
		{
			System.out.println("Error.");
		}
		else
		{
		for (int i = 0; i < size; i++)
		{System.out.print(i+" ");
			for (int j = 0; j < size; j++)
			{
				if (i == j)
				{
					System.out.print("*");
				}
				else if (i+j==size-1)
				{
					System.out.print("*");
				}
				else
				{
					System.out.print(" ");
				}
			}
			System.out.println("");
		}
		}
	}
	if (choice ==4)
	{
		int size = 0;
		System.out.println("Input a size (must be larger than 1):");
		size = myScan.nextInt();
		if (size <= 1)
			{
				System.out.println("Error.");
			}
		else
		{
		for (int i = 0; i < size; i++)
		{System.out.print(i+" ");
			for (int j = 0; j < size; j++)
			{
				if (i+j==size-1)
				{
					System.out.print("*");
				}
				else if ((i)<(size/2) && (j)<(size/2))
				{
					System.out.print("!");
				}
				else if (size%2 == 1 && (i)>(size/2) && (j)>(size/2))
					{
						System.out.print("?");
					}
				else if (size%2 == 0 && (i)>=(size/2) && (j)>=(size/2))
				{
					System.out.print("?");
				}
				else
				{
					System.out.print("~");
				}
			}
			System.out.println("");
		}
}
		}
	if (choice > 4)
	{
		System.out.println("Error.");
		
	}
	}
}

