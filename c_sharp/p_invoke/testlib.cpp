#include <stdio.h>
#include "testlib.h"

int TestLibFunction(const TestStructre* data)
{
  if(data)
    {
      printf("value = %d\n", data->value);
      printf("str   = %s\n", data->str);
    }
  return 0;
}
