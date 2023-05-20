#include "HumanA.hpp"

HumanA::HumanA(std::string set_name, Weapon &set_w) : name(set_name), M4(set_w) {}
HumanA::~HumanA() {}
void HumanA::attack() { std::cout << name << " attacks with their " << M4.getType() << std::endl; }