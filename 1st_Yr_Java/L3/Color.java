/* -----------------------------------------------------------------------------
 *
 * File Name:  Color.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab 
 * Description:  Program will give the color according to the wavelength expressed by the user
 * Date: 9/24/15
 *
 ---------------------------------------------------------------------------- */
import java.util.Scanner;
public class Color {
	public static void main(String[]args) {
		double nm = 0.0;
		Scanner myScan = new Scanner(System.in);
		System.out.println("Input a wavelenth in nm: ");
		nm = myScan.nextDouble();
		if (nm >= 750 || nm <380)
		{	System.out.println("The entered wavelenth is not a part of the visible spectrum");
		}
		else if (nm >= 380 && nm < 450)
		{	System.out.println("The color is Violet.");
		}
		else if (nm >= 450 && nm < 495)
		{	System.out.println("The color is Blue.");
		}
		else if (nm >= 495 && nm < 570)
		{	System.out.println("The color is Green.");
		}
		else if (nm >= 570 && nm < 590)
		{	System.out.println("The color is Yellow.");
		}
		else if (nm >= 590 && nm < 620)
		{	System.out.println("The color is Orange.");
		}
		else if (nm >= 620 && nm < 750)
		{	System.out.println("The color is Red.");
		}
	}
	
}
