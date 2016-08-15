#include "../common/array.h"
#include <iostream>

static void sift_up()
{
	
}

static void sift_down(Array &array, int root, int bottom)
{
	int done, maxChild, temp;
	done = 0;
	
	// bottomは変らない..
	// rootが、子の方へ移動
	while((root * 2 <= bottom) && (!done))
	{
		// root * 2     : left child
		// root * 2 + 1 : right child
		
		if(root * 2 == bottom) {
			// (bottomが、rootの左側の子の場合)
			maxChild = root * 2;
		} else if (array[root * 2] > array[root * 2 + 1]) {
			maxChild = root * 2;
		} else {
			maxChild = root * 2 + 1;
		}
		// maxChildは、より大きな値を持つ方の子

		if(array[root] < array[maxChild]) {
			printf("Swap %d and %d\n", array[root], array[maxChild]);
			array.Swap(root, maxChild);
			root = maxChild;
		} else {
			done = 1;
		}
	}
}

static void heap_sort(Array &array)
{

	// create heap with bottom-up
	for(int i = (array.Size() - 1) / 2 ; i >=0; i--)
	{
		sift_down(array, i, array.Size());
		array.Print("[sift_down]");
	}
	
	array.Print("[afer sift_down]");

	// heap sort
	for(int i= array.Size() - 1; i> 0; i--)
	{
		array.Swap(0, i);
		sift_down(array, 0, i-1);
		array.Print("[heap]");		
	}
}


int main(int argc, const char* argv[])
{

	for(int i=1; i < argc; i++)
	{
		try {
			Array array(std::stoi(argv[i]));
			array.Shuffle(10);
			array.Print("[before sort]");
			heap_sort(array);
			array.Print("[after sort]");
		} catch(std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
