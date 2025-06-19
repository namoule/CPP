#include "CureClass.hpp"

Cure::Cure( void )
{
	this->AMateria::_type = "cure";
}

Cure::Cure( const Cure &i )
{
	this->AMateria::_type = i._type;
}

Cure	&Cure::operator=(const Cure &i)
{
	if (this != &i)
		this->_type = i._type;
	return (*this);
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure()
{
}