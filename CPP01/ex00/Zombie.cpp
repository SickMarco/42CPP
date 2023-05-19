#include "Zombie.hpp"

Zombie::Zombie(std::string set_name){name = set_name;}
Zombie::~Zombie() { std::cout << "Zombie " << name << " died (what?)" << std::endl; }

void Zombie::announce( void ) { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }