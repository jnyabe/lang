class Test {
	public static void main(String args[])
	{
		int[] array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		System.out.println("Test");
		InsertionSort isort = new InsertionSort();
		BubbleSort bsort = new BubbleSort();

		isort.Shuffle(array);
		isort.Print(array);
		isort.Sort(array);
		isort.Print(array);
		
		// bsort.Shuffle(array);
		// bsort.Sort(array);
	}
}
