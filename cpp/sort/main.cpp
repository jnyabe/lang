#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"

#include "insertion_sort.h"

#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "radix_sort.h"

#include <list>

int main(int argc, const char* argv[])
{
	std::list<std::shared_ptr<SortBase>> sorts;
	
	// sorts.push_back(std::make_shared<BubbleSort>());
	// sorts.push_back(std::make_shared<SelectionSort>());
	// sorts.push_back(std::make_shared<InsertionSort>());
	// sorts.push_back(std::make_shared<MergeSort>());
	// sorts.push_back(std::make_shared<QuickSort>());
	// sorts.push_back(std::make_shared<HeapSort>());
	// sorts.push_back(std::make_shared<RadixSort>());
	sorts.push_back(std::make_shared<ShellSort>());	
	for(auto& sort: sorts)
	{
		sort->Run(argc, argv);
	}
	
	return 0;
}
