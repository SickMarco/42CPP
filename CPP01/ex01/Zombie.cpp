#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie() { std::cout << "\e[0;90mZombie " << name << " died (what?)" << std::endl; }

void Zombie::announce( void ) { std::cout << "\e[0;32m" << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::set_name( std::string zName ) { name = zName; }