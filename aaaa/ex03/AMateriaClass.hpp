#ifndef AMATERIACLASS_HPP
#define AMATERIACLASS_HPP

#include "ICharacterClass.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(std::string &type); //[required]
	AMateria(const AMateria &a);

	AMateria &operator=(const AMateria &a);

	std::string const &getType(void) const; //[required]

	virtual AMateria *clone(void) const = 0; //[required]
	virtual void use(ICharacter &target);	 //[required]

	virtual ~AMateria();
};

#endif