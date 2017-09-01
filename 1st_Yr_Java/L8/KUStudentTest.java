import java.util.Scanner;
public class KUStudentTest 
{
	public static void main(String[]args)
	{
		String firstname = null;
		String lastname = null;
		String id = null;
		String dept = null;
		KUStudent kuStud = new KUStudent();
		Scanner myScan = new Scanner(System.in);
		System.out.println("Please input the student's name (firstname lastname): ");
		firstname = myScan.next();
		lastname = myScan.next();
		kuStud.set_name(firstname, lastname);
		System.out.println("Please input the student's KUID and department:");
		id = myScan.next();
		dept = myScan.next();
		kuStud.set_kuinfo(id, dept);
		System.out.println("");
		System.out.println("Student: "+kuStud.get_fname()+" "+kuStud.get_lname());
		System.out.println("KUID: "+kuStud.get_id());
		System.out.println("Department: "+kuStud.get_dpt());
	}
}
