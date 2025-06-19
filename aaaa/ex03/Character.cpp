#include <CharacterClass.hpp>

Character::Character( void )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	this->_name = "Undefined";
}

Character::Character( std::string name )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
	this->_name = name;
}

Character::Character( const Character &c )
{
	int	i = 0;

	while (i < 4)
	{
		this->_inventory[i] = NULL;
		if (c._inventory[i] != NULL)
			this->_inventory[i] = c._inventory[i]->clone();
		i++;
	}
	this->_name = c._name;
}

Character	&Character::operator=( const Character &c )
{
	if (this != &c)
	{
		int	i = 0;

		while (i < 4)
		{
			if (this->_inventory[i] != NULL)
				delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
			if (c._inventory[i] != NULL)
				this->_inventory[i] = c._inventory[i]->clone();
			i++;
		}
		this->_name = c._name;
	}
	return (*this);
}

std::string	const	&Character::getName( void )
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == nullptr)
        {
            this->_inventory[i] = m;
            std::cout << "[Character] Equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }

    std::cout << "[Character] Inventory full, cannot equip " << m->getType() << std::endl;
    delete m;
}


void	Character::unequip( int	idx )
{
	if (idx < 4 && idx >= 0 && this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter	&target )
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}

Character::~Character()
{
	int	i = 0;

	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
		i++;
	}
}