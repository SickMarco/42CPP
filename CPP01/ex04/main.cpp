/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:25 by mbozzi            #+#    #+#             */
/*   Updated: 2023/05/22 14:48:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void replace_line(std::ifstream& file, std::ofstream& file2, std::string& s1, std::string& s2)
{
	std::string line;
	while (std::getline(file, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		file2 << line << std::endl;
	}
	file.close();
	file2.close();
}

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		std::ifstream file;

		file.open(filename.c_str());
		if (file.is_open())
		{
			std::ofstream file2(filename.append(".replace").c_str());
			if (file2)
				replace_line(file, file2, s1, s2);
			else
				std::cout << "\033[31mError: File creation failed." << std::endl;
			return 0;
		}
		else
			std::cout << "\033[31mError: File not found." << std::endl;
		return 1;
	}
	std::cout << "\033[31mError: Wrong arguments. Insert <filename> <s1> <s2>" << std::endl;
	return 1;
}