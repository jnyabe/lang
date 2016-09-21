class InsertionSort extends Sorter {
	
	public int Sort(int[] array)
	{
		for(int i=1; i < array.length; i++)
		{
			for(int j=i-1; j >= 0 && array[j] > array[j+1]; j--)
			{
				Swap(array, j, j+1);
			}
		}
		return 0;
	}
}
