#include "HumanA.hpp"
#include "Weapon.hpp"
#include "HumanB.hpp"


int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");

        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
	return (0);
}

// int main()
// {
//     Weapon club = Weapon("club");  // Création d'une arme "club"
//     HumanA bob("Bob", club);       // Crée un humain avec le nom Bob et l'arme club
//     bob.attack();                  // Bob attaque avec son arme

//     return 0;
// }
