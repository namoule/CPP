#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce(void);
    static Zombie* zombieHorde(int n, std::string name);

private:
    std::string _name;
};

#endif
