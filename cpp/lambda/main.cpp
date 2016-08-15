#include <iostream>
#include <string>

template<typename Func>
void f(Func func)
{
	func();
}


int main(int argc, const char* argv[])
{
	// 	[](){}; minimum lambda
	
	auto func = []{
		std::cout << "Hello, World." <<std::endl;
	};

	printf("(1) Call lambda function\n");
	func();

	printf("(2) Pass lambda function to function\n");
	f(func);

	printf("(3) capture variable\n");
	std::string x = "I am string";
	[&]{std::cout << x << std::endl; }();
	[=]{std::cout << x << std::endl; }();

	printf("(4) \n");
	std::string s1 = "I am s1";
	[&]{s1 = "Overwrite s1!";}();
	[=]{s1 = "Overwrite s1!";}();	
	std::cout << s1 << std::endl;
}
