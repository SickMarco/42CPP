#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			int len = strlen(argv[i]);
			for (int x = 0; x < len; x++)
				std::cout << (char)std::toupper(argv[i][x]);
			std::cout << (argv[i + 1] ? ' ' : '\n');
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}