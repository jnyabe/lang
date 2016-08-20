#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "radix_sort.h"

#include "shell_sort.h"
#include "selection_sort.h"

int main(int argc, const char* argv[])
{
	ShellSort    shsort;
	shsort.Run(argc, argv);

	SelectionSort slsort;
	slsort.Run(argc, argv);
	return 0;
}
