#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int n, std::string name)
{
    if (n <= 0)
        return nullptr;

    Zombie* horde = new Zombie[n];

    for (int i = 0; i < n; ++i)
        horde[i] = Zombie(name); // + std::to_string(i));

    return horde;
}
