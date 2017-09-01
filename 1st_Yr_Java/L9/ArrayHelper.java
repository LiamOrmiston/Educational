/* -----------------------------------------------------------------------------
 *
 * File Name: ArrayHelper.java
 * Author: Liam Ormiston Ljormiston@ku.edu
 * Assignment: EECS-168/169 Lab9
 * Description: Class methods for the Lab09.java. Methods to get the sum, average,
 * max value, and transposes the array.
 * Date: 11/12/15
 *
 ---------------------------------------------------------------------------- */
public class ArrayHelper 
{
	public int [][] arr;
	public void print2DArray(int [][] array)
	{
		for(int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array[i].length; j++)
			{
				if (j == array[i].length - 1)
				{
					System.out.println(array[i][j]);
				}
				else
				{
					System.out.print(array[i][j]+", ");
				}
			}
		}
	}
	public int arraySum(int [] array)
	{
		int sum = 0;
		for (int i = 0; i < array.length; i++)
		{
			sum = sum + array[i];
		}
		return sum;
	}
	public double arrayAvg(int [] array)
	{
		double ave = 0;
		for (int i = 0; i < array.length; i++)
		{
			ave = ave + array[i];
		}
		ave = (ave / array.length);
		return ave;
	}

	public int arraySum2D(int [][] array)
	{
		int sum = 0;
		for(int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array[i].length; j++)
			{
				sum = sum + array[i][j];
			}
		}
		return sum;
	}
	public double arrayAvg2D(int [][] array)
	{
		double avg = 0;
		for(int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array[i].length; j++)
			{
				avg = avg + array[i][j];
			}
		}
		avg = avg / ((array.length) * (array[0].length));
		return avg;
	}
	public int arrayMax2D(int [][] array)
	{
		int max = 0;
		for (int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array[i].length; j++)
			{
				if (array[i][j] > max)
				{
					max = array[i][j];
				}
			}
		}
		return max;
	}
	public int[][] transpose(int [][] array)
	{
		int temp = 0;
		for (int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array[i].length; j++)
			{
				if (i < j)
				{
					temp = array [i][j];
					array [i][j] = array [j][i];
					array [j][i] = temp;
				}
			}
		}
		return array;
	}
}
