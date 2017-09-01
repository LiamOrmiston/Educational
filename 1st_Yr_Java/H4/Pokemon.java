import java.util.Scanner;
public class Pokemon 
{
	//member variables
	private int begHP;
	private int begAtt;
	private int begDef;
	private int hp;
	private int attack;
	private int defense;
	private String name;
	private Dice d20;
	private Dice d6;
	private int attackSpell;
	private int defenseSpell;
	
	//initailizing member variables
	public Pokemon()
	{
		begHP = 0;
		begAtt = 0;
		begDef = 0;
		hp = 0;
		attack = 0;
		defense = 0;
		name = "";
		d20 = new Dice(20);
		d6 = new Dice(6);
		attackSpell = 0;
		defenseSpell = 0;
	}
	//the attacking of two pokemon
	public boolean attack(Pokemon opponent)
	{
		//who is attacking who
		System.out.println(this.getName()+" is attacking "+opponent.getName());
		int attackBonus = 0;
		int defenseBonus = 0;
		Scanner myScan = new Scanner(System.in);
		//displays the random attack and defense bonuses that are added to the pokemon's attack and defense lvl
		attackBonus = d20.roll();
		System.out.println(this.getName()+" rolls an attack bonus of "+attackBonus);
		defenseBonus = d20.roll();
		System.out.println(opponent.getName()+" rolls an defense bonus of "+defenseBonus);
		this.attack = this.attack + attackBonus;
		opponent.defense = opponent.defense + defenseBonus;
		int attack = 0;
		//if the attack wont miss then the user is given options
		if (this.attack > opponent.defense)
		{
			int choice = 0;
			int Physical = 1;
			int IncreaseA = 2;
			int IncreaseD = 3;
			//can either physically attack, increase owns attack level or defense level by 5 
			System.out.println("What would you like to do?");
			System.out.println("Physical attack (1), increase attack spell (2), or increase defense spell (3)?");
			choice = myScan.nextInt();
			//user can only user spells once
			if ((choice == IncreaseA && this.attackSpell == 1) || (choice == IncreaseD && this.defenseSpell == 1))
			{
				do
				{
					System.out.println("You can only use this spell once. Please choose another option.");
					System.out.println("Physical attack (1), increase attack spell (2), or increase defense spell (3)?");
					choice = myScan.nextInt();
				}
				while ((choice == IncreaseA && this.attackSpell == 1) || (choice == IncreaseD && this.defenseSpell == 1));
			}
			//increases attack or defense by 5
			if (choice == IncreaseA && this.attackSpell == 0)
			{
				this.attack = this.attack + 5;
				this.attackSpell++;
			}

			if (choice == IncreaseD && this.defenseSpell == 0)
			{
				this.defense = this.defense + 5;
				this.defenseSpell++;
			}
			//rolls 3 6sided die and the sum is the damage of the attack
			if (choice == Physical)
			{
				int roll1 = 0;
				int roll2 = 0;
				int roll3 = 0;
				System.out.println("The attack hits dealing a 3-D6 damage!");
				roll1 = d6.roll();
				roll2 = d6.roll();
				roll3 = d6.roll();
				attack = roll1 + roll2 + roll3;
				System.out.println("The rolls are "+roll1+", "+roll2+", and "+roll3+" totalling: "+attack+" damage!");
				opponent.hp = opponent.hp - attack;
			}
			//informs the user if the opponent was defeated
			if (opponent.hp <= 0)
			{
				System.out.println(opponent.getName()+" has been defeated!");
			}
			//if opponent wasn't defeated then displays their hp left
			else
			{
				System.out.println(opponent.getName()+" has "+opponent.hp+" hit points left");
			}
			System.out.println("");
		}
		//attack can miss
		else
		{
			System.out.println("The attack missed!");
		}
		return (opponent.hp <= 0);
	}
	
	//getters and setters for all private member variables
	public void setHP(int HP)
	{
		begHP = HP;
		hp = HP;
	}
	public int getHP()
	{
		return hp;
	}
	public void setAttack(int Attack)
	{
		begAtt = Attack;
		attack = Attack;
	}
	public int getAttack()
	{
		return attack;
	}
	public void setDefense(int Defense)
	{
		begDef = Defense;
		defense = Defense;
	}
	public int getDefense()
	{
		return defense;
	}
	public void setName(String Name)
	{
		name = Name;
	}
	public String getName()
	{
		return name;
	}
	public void setAttackSpell(int a)
	{
		attackSpell = a;
	}
	public int getAttackSpell()
	{
		return attackSpell;
	}
	public void setDefenseSpell(int d)
	{
		defenseSpell = d;
	}
	public int getDefenseSpell()
	{
		return defenseSpell;
	}
	public int getBegHP()
	{
		return begHP;
	}
	public int getBegAtt()
	{
		return begAtt;
	}
	public int getBegDef()
	{
		return begDef;
	}
}
