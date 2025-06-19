#ifndef MATERIASOURCECLASS_HPP
#define MATERIASOURCECLASS_HPP

#include "IMateriaSourceClass.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_invent[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &m);
		MateriaSource &operator=(const MateriaSource &m);
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
		~MateriaSource();
};

#endif