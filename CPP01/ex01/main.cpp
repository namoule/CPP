#include "Zombie.hpp"

int main(void)
{
    int i = 0;
    int n = 5;
    Zombie* horde = Zombie::zombieHorde(n, "Zombie");

    if (horde)
    {
        std::cout << "premier zombie : " << &horde[0] << " adresse retournee: "<< horde << std::endl;
        while(i < n)
            horde[i++].announce();
        delete[] horde;
    }
    else 
        std::cout << "Erreur : La horde n'a pas pu être créée" << std::endl;
    return 0;
}

