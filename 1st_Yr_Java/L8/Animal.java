
public class Animal 
{
	private String Type;
	private String Sound;
	public Animal()
	{
		 Type = null;
		 Sound = null;
	}
	public void set_Type(String a)
	{
		Type = a;
	}
	public void set_Sound(String noise)
	{
		Sound = noise;
	}
	public String get_Type()
	{
		return (Type);
	}
	public String get_Sound()
	{
		return (Sound);
	}
}
