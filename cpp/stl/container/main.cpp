#include <assert.h>
#include "container.h"

int main(int argc, const char* argv[])
{
	int ret = 0;
	Container c;
	
	ret = c.Init();
	assert(ret == 0);

	ret = c.TestSize();
	assert(ret == 0);
	
	ret = c.TestEmpty();
	assert(ret == 0);
	
	ret = c.Dump();
	assert(ret == 0);	

	ret = c.Clear();
	assert(ret == 0);
	
	ret = c.Dump();
	assert(ret == 0);
	
	return ret;
}
