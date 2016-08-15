#include <stdio.h>
#include "sema.h"

int main(int argc, const char* argv[])
{
  Sema sema("test", 3);

  printf("Try Aquire(%d)\n", 3);
  sema.Aquire(3);
  printf("done\n");
  printf("Try Aquire(%d)\n", 2);
  sema.Aquire(2);
  printf("done\n");
  return 0;
}
