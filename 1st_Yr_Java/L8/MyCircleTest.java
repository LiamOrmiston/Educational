import java.util.Scanner;
public class MyCircleTest 
{
	public static void main(String[] args) 
	{
// Declare a new circle called myCircle
// Declare any other variables you need (e.g. Scanner, double)
		
		MyCircle myCircle = new MyCircle();
		Scanner myScan = new Scanner(System.in);
		double rad = 0.0;
		
//Get a radius from the user
		
       System.out.print("Please input a radius: ");
       rad = myScan.nextDouble();
       myCircle.setRadius(rad);   
       
//Display a message to the screen that says "My circle has a radius of <put the radius here>"
       
       System.out.println("My circle has a radius of "+myCircle.getRadius());
       
//Use the method area() from myCircle to print the area 
       
       System.out.println("Area = "+myCircle.area());
       
//Use the method circumference() from myCircle to print the circumference
       
       System.out.println("Circumference = "+myCircle.circumference());
       
//Using only a method call to diameter()  to print the diameter
       
       System.out.println("Diameter = "+myCircle.diameter());
	}


}
