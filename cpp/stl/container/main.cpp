#include <assert.h>
#include "container.h"

int main(int argc, const char* argv[])
{
	int ret = 0;
	Container c;

	ret = c.TestInsert();
	assert(ret == 0);

	ret = c.TestAccess();
	assert(ret == 0);

	ret = c.TestLookFor();
	assert(ret == 0);
	
	ret = c.TestErase();
	assert(ret == 0);
	
	
	return ret;
}
