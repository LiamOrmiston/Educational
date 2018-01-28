
public class OldMacDonald 
{
	private String type;
	private String sound;
	public OldMacDonald()
	{
		type = null;
		sound = null;
	}
	public void set_Animal(String t, String s)
	{
		type = t;
		sound = s;
	}


	public void sing()
	{
		System.out.println("Old MacDonald had a farm, EE-I-EE-I-O");
		System.out.println("And on the farm he had a "+type+" EE-I-EE-I-O");
		System.out.println("With a "+sound+"-"+sound+" here, and a "+sound+"-"+sound+" there,");
		System.out.println("Here a "+sound+", there a "+sound+", everywhere a "+sound+"-"+sound+",");
		System.out.println("Old MacDonald had a farm, EE-I-EE-I-O");
	}
}
