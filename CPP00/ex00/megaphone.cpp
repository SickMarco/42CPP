#include <iostream>
#include <string>
#include <cctype> 
#include <cstring>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			int len = strlen(argv[i]);
			for (int x = 0; x < len; x++)
				argv[i][x] = std::toupper(argv[i][x]);
		}
		for(int i = 1; i < argc; i++)
			std::cout << argv[i] << ' ';
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}