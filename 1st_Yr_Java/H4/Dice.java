import java.util.Random;
public class Dice 
{
	//member variable
	final int numSides;
	//member variable initialized
	public Dice(int sides)
	{
		numSides = sides;
	}
	//the "rolling" of the die
	public int roll()
	{
		Random myRand = new Random ();
		return myRand.nextInt(numSides);
	}
}
