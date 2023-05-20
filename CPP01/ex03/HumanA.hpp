#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon &M4;
public:
	HumanA(std::string set_n, Weapon &set_w);
	~HumanA();
	void attack();
};