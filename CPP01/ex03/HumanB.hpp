#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *AK47;
public:
	HumanB( std::string new_n );
	~HumanB();
	void attack();
	void setWeapon( Weapon &set_w );
};



#endif