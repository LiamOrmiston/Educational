/* -----------------------------------------------------------------------------
 *
 * File Name: MethodPractice.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab5
 * Description: 
 * Date: 10/08/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class MethodPractice 
{
	public static void main(String[]args)
	{
		int x = 0;
		int z = 0;
		int answer = 0;
		Scanner myScan = new Scanner(System.in);
		System.out.println("Input two numbers:");
		x = myScan.nextInt();
		z = myScan.nextInt();
		answer = max(x, z);
		System.out.println("The max of "+ x +" and "+ z +" is: "+ answer);
		
		System.out.println("");
		
		double radius = 0.0;
		double area = 0.0;
		System.out.print("Input a radius: ");
		radius = myScan.nextDouble();
		area = area(radius);
		System.out.println("The ear of a sphere with this radius is: "+ area);
		
		System.out.println("");
		
		String input = "";
		int times = 0;
		System.out.println("Input a string:");
		input = myScan.nextLine();
		input = myScan.nextLine();
		System.out.println("");
		System.out.print("How many times do you want to print it?: ");
		times = myScan.nextInt();
		printWord(input, times);
	}
	public static int max(int a, int b)
	{
		if (a > b)
		{
			return(a);
		}
		else
		{
			return(b);
		}
	}
	public static double area(double radius)
	{
		double answer = 0.0;
		double pi = 3.14159;
		answer = 4 * radius * radius * pi;
		if (radius == 0.0)
		{
			return (0.0);
		}
		else
		{
			return (answer);
		}
	}
	public static void printWord(String word, int timesToPrint)
	{
		for (int i = 0; timesToPrint >  i; i++)
		{
			System.out.println(word);
		}
	}
}
