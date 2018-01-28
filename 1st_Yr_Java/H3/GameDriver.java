/* File Name: GameDriver.java 
*Author: Liam Ormiston 
*KUID: 2767240
*Email Address: ljormiston@ku.edu 
*Homework Assignment Number: 3 
*Description: A hangman game that lets the user guess a character in a secret word. 
The user can guess the word once and if missed, can only guess characters for the rest
of that game. The user gets 7 misses before the game ends. At the end of the game the
user and choose to play again using their own word.
*Last Changed: 11/09/2015 */
import java.util.Scanner;
public class GameDriver 
{
	public static void main(String[]args)
	{

		Hangman h1 = new Hangman ("big bang");
		playGame(h1);
	}
	
	//method runs the hangman game.
	public static void playGame(Hangman h1)
	{
		String guess = "";
		Scanner myScan = new Scanner(System.in);
		//displays this only at the beginning of each game.
		System.out.println("Welcome to the Hangman Game!");
		System.out.println("----------------------------");
		System.out.println("");
		//displays this until game is over.
		do
		{
		System.out.println("Guess this: "+h1.getDisguisedword());
		System.out.println("Guesses so far: "+h1.getGuessCount());
		System.out.println("Misses: "+h1.getMissedMarker());
		System.out.print("Enter your guess character: ");
		guess = myScan.nextLine();
		guess = guess.toLowerCase();
		//if the user enters a String
		if (guess.length() > 1 && h1.areWordGuessesAllowed())
		{
			if (guess.length() != h1.getDisguisedword().length()) 
			{
				System.out.println("I'm sorry, your guess is not the correct length.");
				System.out.println("Please enter a guess of the correct length: ");
				guess = myScan.nextLine();
				guess = guess.toLowerCase();
			}
			//the method will check if the guessed String is the same length as the secret word. If not then it will ask
			//the user for another guess at no penalty to the user. 
			if (h1.guessWord(guess) == false)
			{
				System.out.println(guess+" is not the sercet word. You can no longer guess the complete word.");
			}
			else
			{
				System.out.println(guess+" is the sercet word!");
				System.out.println("");
			}
			//if the guessed String is the same length as the secret word then it will check to see if they are the same word.
			//if so then it will tell the user they guessed the right word.
		}

		//if the user just enters a character
		else
		{
			if (h1.guessCharacter(guess.charAt(0)) == false)
			{
				System.out.println(guess.charAt(0)+" is not in the sercet word. Death draws closer.");
			}
			else
			{
				System.out.println(guess.charAt(0)+" is in the sercet word!");
			}
			System.out.println("");
		}
		//checks to see if the guessed character appears in the secret word. Will tell the user if it does or doesn't.
		}
		while (h1.isGameOver() == false);
		endGame(h1);
	}
	//method will run until the game is over. Once the game is over then the method will call the endGame method.
	
	//runs if game is over.
	public static void endGame(Hangman h1)
	{
		String again = "yes";
		Scanner myScan = new Scanner(System.in);
		System.out.println("Game Over!");
		//if the user guess the right word.
		if (h1.getMissesCount() != h1.getMissedMarker().length())
		{
			System.out.println("Congratulations! You guessed the secret word: "+h1.getDisguisedword()+" in "+h1.getGuessCount()+" guesses!");
		}
		//if the user ran out of guesses.
		else
		{
			System.out.println("You died. Next time, guess as if your life depended on it.");
		}
		//asks the user if they want to play again.
		System.out.println("Do you want to play again? (yes/no):");
		again = myScan.nextLine();
		again = again.toLowerCase();
		//if the user wants to play again then method will ask them for a new secret word
		if (again.equals("yes"))
		{
			String newWord = "";
			System.out.print("Input a new secret word: ");
			newWord = myScan.nextLine();
			newWord = newWord.toLowerCase();
			Hangman h2 = new Hangman(newWord);
			for (int i = 0; i < 100; i++)
			{
				System.out.println("");
			}
			playGame(h2);
		//will play another game with the new given secret word.
		}
		//if the user does not want to play again
		else
		{
			System.out.println("");
			System.out.println("Thanks for playing "+h1.getGamesPlayed()+" game(s) of Hang Man!");
		}
		//thanks user for playing and tells them how many games were played.
	}
}
