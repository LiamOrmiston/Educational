import java.util.Scanner;

/* -----------------------------------------------------------------------------
 *
 * File Name: WordGuessingGame.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab03
 * Description: The user guesses a word and will continue guessing
 * until the correct word is guessed. The correct word is "valentine".
 * Date: 10/01/15
 *
 ---------------------------------------------------------------------------- */
public class WordGuessingGame 
	{	public static void main(String[]args)
	{String answer = "valentine";
	String guess = "";
	Scanner myScan = new Scanner(System.in);
	System.out.println("Welcome to the word guessing game.");
	System.out.print("Guess a word: ");
	guess = myScan.nextLine();
		while (!(guess.equals(answer)))
			{	System.out.print("Incorrect. Guess again: ");
				guess = myScan.nextLine();}

		System.out.println("You win!");	}
	}

