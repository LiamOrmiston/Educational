/* -----------------------------------------------------------------------------
 *
 * File Name: NumberGuessingGame.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab03
 * Description: The user guesses a number and the program will tell
 * the user whether they are too high or too low based on the pre-determined
 * number.
 * Date: 10/01/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class NumberGuessingGame 
{	public static void main(String[]args)
	{int answer = 73;
	int guess = 0;
	Scanner myScan = new Scanner(System.in);
	System.out.println("Welcome to the number guessing game.");
	System.out.print("Guess a number: ");
	guess = myScan.nextInt();
		while (guess != answer)
		{	if (guess > answer)
			{	System.out.println("Sorry, your guess is too high.");
				System.out.print("Guess a number: ");
				guess = myScan.nextInt();}
			else
			{	System.out.println("Sorry, your guess is too low.");
				System.out.print("Guess a number: ");
				guess = myScan.nextInt();	}
		}
		System.out.println("You win!");
	}
}


