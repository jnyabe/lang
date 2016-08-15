#include <string>
#include "custom_allocator.h"

int main(int argc, const char* arvg[])
{
  typedef std::basic_string<char, std::char_traits<char>, 
			    custom_allocator<char> > custom_string;

  custom_string test;
  test = "hello world";


  return 0;
}
