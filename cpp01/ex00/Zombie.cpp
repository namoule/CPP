#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
    return new Zombie(name);
}


void Zombie::randomChump(std::string name)
{
    Zombie* zmb = new Zombie(name);
    std::cout << zmb->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    delete zmb;
}
