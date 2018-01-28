/* File Name: Hangman.java 
*Author: Liam Ormiston 
*KUID: 2767240
*Email Address: ljormiston@ku.edu 
*Homework Assignment Number: 3 
*Description: A hangman game that lets the user guess a character in a secret word. 
The user can guess the word once and if missed, can only guess characters for the rest
of that game. The user gets 7 misses before the game ends. At the end of the game the
user and choose to play again using their own word.
*Last Changed: 11/09/2015 */
public class Hangman 
{
	// member variables
	private final String secretWord;
	private  char [] disguisedWord;
	private  int guessCount;
	private  int missesCount;
	private  int MAX_MISSES_ALLOWED;
	private  char [] missedMarkers;
	private  int wordGuess;
	public static int GamesPlayed = 0;
	
	//constructor assuming a value for secretWord is declared. 
	public Hangman(String secret)
	{
		secretWord = secret;
		disguisedWord = new char[secretWord.length()];
		setDisguisedWord();
		MAX_MISSES_ALLOWED = 7;
		missedMarkers = new char [MAX_MISSES_ALLOWED];
		guessCount = 0;
		missesCount = 0;
		wordGuess = 0;
		setMissedMarkers();
		Hangman.GamesPlayed ++;
	}
	// will run Hangman game as the secretWord being whatever the user enters.
	
	//method for when a user guesses a single character. assumes that the user will enter a letter.
	public boolean guessCharacter (char c)
	{
		c = Character.toLowerCase(c);
		boolean guess = false;
		for (int i = 0; i < secretWord.length(); i++)
		{
		if ( c == secretWord.charAt(i))
		{
			disguisedWord [i] = c;
			guess = true;
		}
		}
		if (guess == false)
		{
			missedMarkers [missesCount] = 'X';
			missesCount ++;
		}
		guessCount ++;
		return (guess);
	}
	//if user enters a single letter the method will check if it matches any characters
	//in the secretWord. If so then returns True and changes "?" in disguisedWord to the character.
	//If the character is not found the will return False and will change "O" in missedMarkers to "X".
	//It will also add to the missesCount value by one. Once this method runs it will add to the guessCount
	//by one.
	
	//method to check if the game is over. Assumes game is not over until conditions are met. 
	public  boolean isGameOver ()
	{
		boolean game = false;
		if (missesCount == MAX_MISSES_ALLOWED || isFound() == true )
		{
			game = true; 
		}
		return (game);
	}
	//if user misses 7 times or if they solved the word then the method will return true.
	
	//method to check if the user solved the secret word. Assumes that if the user solves one character, then
	//the "?" will be replaced with the character.
	public  boolean isFound ()
	{
		boolean found = true;
		for (int i = 0; i < disguisedWord.length; i++)
		{
			if (disguisedWord [i] == '?')
			{
				found = false;
			}
		}
		return (found);
	}
	//method will check to see if there are any "?" left in the disguised word. If there are then method
	//will return false. If no "?" are found then the user solved the word and will return true.
	
	//method to access the private variable disguisedWord. Assumes there is a disguised word value.
	public  String getDisguisedword ()
	{
		String Disguisedword = new String (disguisedWord);
		return(Disguisedword);
	}
	//if disguised word has a value then it will return its value.
	
	//method to access the private variable guessCount. Assumes there is a value.
	public  int getGuessCount ()
	{
		return (guessCount);
	}
	//if guessCount has a value then it will return its value.
	
	//method to access the private variable missesCount. Assumes there is a value.
	public int getMissesCount ()
	{
		return (missesCount);
	}
	//if missesCount has a value then it will return its value.
	
	//method to access the private variable missesCount. Assumes there is a value
	public String getMissedMarker ()
	{
		String Markers = new String (missedMarkers);
		return(Markers);
	}
	//if missedMarkers has a value then it will return its value.
	
	//method to access the private variable missesCount. Assumes there is a value
	public  int getGamesPlayed()
	{
		return (GamesPlayed);
	}
	//if GamesPlayed has a value then it will return its value.
	
	//method for when a user guesses the entire secret word with a String. Assumes that the user will only enter letters.
	public boolean guessWord (String word)
	{
		boolean guess = false;
		word = word.toLowerCase();
		if (word.equals(secretWord))
		{
			guess = true;
			for (int i = 0; i < secretWord.length(); i ++)
			{
				disguisedWord [i] = secretWord.charAt(i);
			}
		}
		guessCount ++;
		wordGuess ++;			
		return guess;
	}
	//if user enters a String for a guess, the method will check if it matches the secret word String.
	//If so, then returns True and changes the remaining "?" in disguisedWord to the characters of the secret word.
	//If the secret word is not found then will return False. It will not add to the missesCount value. 
	//Once this method runs it will add to the guessCount and wordGuess by one.
	
	//method to check if the user can guess the secret word with a String. Assumes the user can until conditions
	//are not met.
	public  boolean areWordGuessesAllowed()
	{
		boolean guess = true;
		if (wordGuess == 1)
		{
			guess = false;
		}
		return guess;
	}
	//if the user is only allowed 1 word guess. If the user runs the guessWord method once then they are not allowed
	//to run it again. This method checks to see if word guess equals one. If it is then it will return false.
	
	//method will disguised the secret word as question marks. Assumes secretWord does not equal null.
	private  void setDisguisedWord()
	{
		for (int i = 0; i < secretWord.length(); i ++)
		{
			if (secretWord.charAt(i) == ' ')
			{
				disguisedWord [i] = ' ';
			}
			else
			{
				disguisedWord [i] = '?';
			}
		}
	}
	//according to the length of the secret word, the method will assign a "?" for every character and a space for every
	//space in the secret word.
	
	//method sets each char [] as an "O".
	private  void setMissedMarkers() 
	{
		for (int i = 0; i < MAX_MISSES_ALLOWED; i++)
		{
			missedMarkers [i] = 'O';
		}
		
	}
	//Will set to "OOOOOOO" since the max misses allowed is 7.
}
