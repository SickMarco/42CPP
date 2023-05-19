#include <iostream>
#include <string>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "STRING ADDRESS: " << &string << std::endl;
	std::cout << "POINTER ADDRESS: " << stringPTR << std::endl;
	std::cout << "REFERENCE ADDRESS: " << &stringREF << '\n' << std::endl;

	std::cout << "STRING VALUE: " << string << std::endl;
	std::cout << "POINTER VALUE: " << *stringPTR << std::endl;
	std::cout << "POINTER VALUE: " << stringREF << std::endl;

}