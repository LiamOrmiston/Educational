/* -----------------------------------------------------------------------------
 *
 * File Name: Palindrome.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab5
 * Description: Program tells user length of an number inputed, then give
 * the user the number in reverse order and tell the user whether the number
 * is a palindrome or not. The program will run this program as long as the
 * user wants to run the program again.
 * Date: 10/15/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Palindrome 
{
	public static void main(String[]args)
	{
		int num = 0;
		int length = 0;
		int reverse = 0;
		boolean palindrome = true;
		int again = 0;
		Scanner myScan = new Scanner(System.in);
		System.out.println("Please enter a Number:");
		num = myScan.nextInt();
		length = lengthOfNumber(num);
		System.out.println("Length of the Number is: "+length);
		reverse = reverse(num);
		System.out.println("The Reverse of the Number is: "+reverse);
		palindrome = isPalindrome(num, reverse);
		if (palindrome == true)
		{
			System.out.println("The number is a Palindrome.");
		}
		else
		{
			System.out.println("The Number is not a Palindrome.");
		}
		System.out.println("");
		System.out.println("Want to try again?(y=1/n=0");
		again = myScan.nextInt();
		while (again == 1)
		{
			System.out.println("Please enter a Number:");
			num = myScan.nextInt();
			length = lengthOfNumber(num);
			System.out.println("The Length of the Number is: "+length);
			reverse = reverse(num);
			System.out.println("The Reverse of the Number is: "+reverse);
			palindrome = isPalindrome(num, reverse);
			if (palindrome == true)
			{
				System.out.println("The number is a Palindrome.");
			}
			else
			{
				System.out.println("The Number is not a Palindrome.");
			}
			System.out.println("");
			System.out.println("Want to try again?(y=1/n=0)");
			again = myScan.nextInt();
		}
		if (again == 0)
		{
			System.out.println("Thank you!");
		}
	}
	public static int lengthOfNumber(int x)
	{
		int i = 0;
		while (x!=0)
		{
			x = x/10;
			i++;
		}
		return(i);
	}
	public static int reverse(int x)
	{
		int i = 0;
		while (x != 0)
		{
			i = i * 10;
			i = i + x%10;
			x = x/10;
		}
		return(i);
	}
	public static boolean isPalindrome(int x, int y)
	{
		if (x==y)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
}
