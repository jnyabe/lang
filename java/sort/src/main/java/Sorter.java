import java.util.*;
	
abstract class Sorter {
	
	abstract public int Sort(int[] array);
	
	public void Swap(int[] array, int n, int m)
	{
		// System.out.println("Swap " + n + " and " + m);
		int tmp = array[n];
		array[n] = array[m];
		array[m] = tmp;
	}
	
	public void Shuffle(int[] array)
	{
		Random rnd = new Random();
		for(int i=0; i < array.length - 1; i++)
		{
			int j = rnd.nextInt(array.length - i - 1) + (i + 1);
			Swap(array, i, j);
		}
	}
	
	public void Print(int[] array)
	{
		System.out.println(Arrays.toString(array));
	}
}
