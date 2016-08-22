#include "shell_sort.h"

int ShellSort::Sort(Array &array) const
{

	int inc = 4;

	while(inc > 0)
	{
		for(int i=0; i < array.Size(); i++)
		{
			int j = i;
			int temp = array[i];
			while((j>=inc) && (array[j-inc] > temp))
			{
				array[j]= array[j-inc];
				j = j - inc;
			}
			array[j] = temp;
		}
		array.Print("->");
		if(inc / 2 != 0)
			inc = inc / 2;
		else if(inc == 1)
			inc = 0;
		else
			inc = 1;
	}
	
	return 0;
}
