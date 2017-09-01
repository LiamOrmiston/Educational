/* -----------------------------------------------------------------------------
 *
 * File Name: Letter_Counter.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab10
 * Description: Scans a valid file and shows how many times each character appears 
 * and what character(s) appears the most. The user can pick whether to analyze the 
 * file case sensitively or not.
 * Date: 11/22/15
 *
 ---------------------------------------------------------------------------- */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;
public class Letter_Counter 
{
	public static void main(String[]args)
	{
		String Inputfilename = "";
		String Outputfilename = "";
		Scanner myScan = new Scanner(System.in);
		int [] LowCase = new int [26];
		int [] Myarr = new int [58];
		String choice = "";
		System.out.print("Do you want to be case sensitive?(y/n): ");
		choice = myScan.nextLine();
		if (choice.equals("y"))
		{
			Inputfilename = ReadFile(Inputfilename, Myarr, myScan);
		}
		else
		{
			Inputfilename = ReadLowerCase(Inputfilename, LowCase, myScan);
		}
		System.out.println("");
		System.out.print("Input an out file name: ");
		Outputfilename = myScan.nextLine();
		System.out.println("");
		System.out.println("Reading from "+Inputfilename);
		System.out.println("");
		if (choice.equals("y"))
		{
			WriteFile(Outputfilename, Myarr);
			System.out.println("Results:");
			System.out.println("");
			PrintFile(Outputfilename);
			System.out.println("");
			max(Myarr);
		}
		else
		{
			WriteLowCase(Outputfilename, LowCase);
			System.out.println("Results:");
			System.out.println("");
			PrintFile(Outputfilename);
			maxLowCase(LowCase);
		}
		
		

	}
	public static String ReadFile (String Inputfilename, int arr [], Scanner myScan)
	{
		System.out.print("Input a file name: ");
		Inputfilename = myScan.nextLine();
		boolean again = true;
		FileReader myFileReader= null;
		BufferedReader myBufferedReader= null;
		while(again == true)
		{
		try
		{
		    myFileReader= new FileReader(Inputfilename);
		    myBufferedReader= new BufferedReader(myFileReader);			
		    
		    String line;
		    line = myBufferedReader.readLine();
		    while( line != null)
		    {	
		    	int x = 0;
		    	for (int i = 0; i < line.length(); i++)
		    	{
		    		char c = line.charAt(i);
		    		x = (int) c;
		    		if (x > 64 && x < 91 || x > 96 && x < 123)
		    		{
			    		arr[x-65] = (arr[x-65]+1);
		    		}
		    	}
		      line = myBufferedReader.readLine();
		    }
		    myBufferedReader.close();
		    again = false;
		}
		catch (Exception e)
		{
			System.out.println("Invalid filename given. Input another.");
			System.out.print("Input a file name: ");
			Inputfilename = myScan.nextLine();
		}
		}
		return (Inputfilename);
	}	

public static String ReadLowerCase (String Inputfilename,int arr [], Scanner myScan)
{
	System.out.print("Input a file name: ");
	Inputfilename = myScan.nextLine();
	boolean again = true;
	FileReader myFileReader= null;
	BufferedReader myBufferedReader= null;
	while(again == true)
	{
	try
	{
	    myFileReader= new FileReader(Inputfilename);
	    myBufferedReader= new BufferedReader(myFileReader);			
	    
	    String line;
	    line = myBufferedReader.readLine();
	    while( line != null)
	    {	
	    	line = line.toLowerCase();
	    	int x = 0;
	    	for (int i = 0; i < line.length(); i++)
	    	{
	    		char c = line.charAt(i);
	    		x = (int) c;
	    		if (x > 96 && x < 123)
	    		{
		    		arr[x-97] = (arr[x-97]+1);
	    		}
	    	}
	      line = myBufferedReader.readLine();
	    }
	    myBufferedReader.close();
	    again = false;
	}
	catch (Exception e)
	{
		System.out.println("Invalid filename given. Input another.");
		System.out.print("Input a file name: ");
		Inputfilename = myScan.nextLine();
	}
	}
	return (Inputfilename);
}
public static void WriteFile (String FileName, int write [])
{
	FileWriter myFileWriter= null;
	BufferedWriter myBufferedWriter = null;
	try{
			myFileWriter = new FileWriter(FileName);
			myBufferedWriter = new BufferedWriter(myFileWriter);
			char c = ' ';
			int x = 0;
			for (int i = 0; i < write.length; i++)
			{
				x = i+65;
				c = (char) x;
				if(x > 64 && x < 91 || x > 96 && x < 123)
				{
					myBufferedWriter.write(c+"="+Integer.toString(write[i]));
					myBufferedWriter.newLine();
				}
			}

			myBufferedWriter.close();
		}
	  catch (Exception e)
	  {
		  //Catch exception if any
		  System.err.println("Error: " + e.getMessage());
	  }
}
public static void WriteLowCase (String FileName, int write [])
{
	FileWriter myFileWriter= null;
	BufferedWriter myBufferedWriter = null;
	try{
			myFileWriter = new FileWriter(FileName);
			myBufferedWriter = new BufferedWriter(myFileWriter);
			char c = ' ';
			int x = 0;
			for (int i = 0; i < write.length; i++)
			{
				x = i+97;
				c = (char) x;
				if(x > 64 && x < 91 || x > 96 && x < 123)
				{
					myBufferedWriter.write(c+"="+Integer.toString(write[i]));
					myBufferedWriter.newLine();
				}
			}

			myBufferedWriter.close();
		}
	  catch (Exception e)
	  {
		  //Catch exception if any
		  System.err.println("Error: " + e.getMessage());
	  }
}
public static void PrintFile (String file)
{
	FileReader myFileReader= null;
	BufferedReader myBufferedReader= null;

	try
	{
	    myFileReader= new FileReader(file);
	    myBufferedReader= new BufferedReader(myFileReader);			

	    //read each line and modify accordingly
	    String line;
	    line = myBufferedReader.readLine();
	    while( line != null)
	    {
	      //Do something with the line
	    	System.out.println(line);
	      //Now, read in a new line 
	      line = myBufferedReader.readLine();
	    }
	    		           
	    myBufferedReader.close();//close the file
	}
	catch (Exception e)
	{
	   System.out.println(e.getMessage()); //print what went wrong
	}
}
public static void max(int [ ] max)
{
	int x = max [0];
	char letter = 0;
	int c = 0;
	int [] chars = new int [max.length];
	for (int i = 1; i < max.length; i++)
	{
		if (x < max [i])
		{
			x = max [i];
		}
	}
	for (int i = 0; i < max.length; i++)
	{
		if (x == max [i])
		{
			if(max[i] < 26)
			{
				c = (i + 65);
				System.out.print(((char)c)+", ");
			}
			if(max[i] > 25)
			{
				c = (i + 90);
				System.out.print(((char)c)+", ");
			}
		}
	}
	
	System.out.print("appeared "+x+" times.");
}
public static void maxLowCase(int [ ] max)
{
	int x = max [0];
	char letter = 0;
	int c = 0;
	int [] chars = new int [max.length];
	for (int i = 1; i < max.length; i++)
	{
		if (x < max [i])
		{
			x = max [i];
		}
	}
	for (int i = 0; i < max.length; i++)
	{
		if (x == max [i])
		{
			c = (i + 97);
			System.out.print(((char)c)+", ");
		}
	}
	
	System.out.print("appeared "+x+" times.");
}
}
