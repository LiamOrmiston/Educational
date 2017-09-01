import java.util.Scanner;
public class Lab6_Strings 
{
	public static void main(String[]args)
	{
		int size = 0;
		String [ ] arr = null;
		String max = "";
		String min = "";
		String s = "";
		Scanner myScan = new Scanner(System.in);
		do
		{
			System.out.print("Input an array size for your words array: ");
			size = myScan.nextInt();
		}
		while (size < 0);
		arr = new String [size];
		System.out.println("Now please enter "+ size +" words");
		myScan.nextLine();
		for (int i = 0; i < arr.length; i++)
		{	
			System.out.print("Input a word: ");
			s = myScan.nextLine();
			arr [i] = s;
		}
		max = max(arr);
		System.out.println("The longest word is: "+ max);
		min = min(arr);
		System.out.println("The shortest word is: "+ min);
	}
	public static String max(String [ ] max)
	{
		String s = "";
		String l = "";
		for (int i = 1; i < max.length; i++)
		{
			s = max[0];
			l = max[i];
			if (s.length() < l.length())
			{
				s = l;
			}
		}
		return (s);
	}
	public static String min(String [ ] min)
	{
		String s = "";
		String l = "";
		for (int i = 1; i < min.length; i++)
		{
			s = min[0];
			l = min[i];
			if (s.length() > l.length())
			{
				s = l;
			}
		}
		return (s);
	}
}
