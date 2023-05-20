#include <iostream>
#include <fstream>
#include <cstring>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3]; 
		std::ifstream file;
		
		file.open(filename.c_str());
		if (!file.is_open()) { std::cout << "Error: File not found." << std::endl; return 1; }
		else
		{
			std::string line;
			std::ofstream file2(filename.append(".replace").c_str());
			while (std::getline(file, line))
			{
				size_t pos = 0;
				while ((pos = line.find(s1, pos)) != std::string::npos)
				{
					line.replace(pos, s2.length(), s2);
					pos += s2.length();
					file2 << line << std::endl;
				}
			}
			file.close();
			file2.close();
		}
	}
	else
	{ std::cout << "Error: Wrong arguments. Insert <filename> <s1> <s2>" << std::endl; return 1; };
	return 0;
}