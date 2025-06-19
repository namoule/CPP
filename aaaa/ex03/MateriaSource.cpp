#include "MateriaSourceClass.hpp"

MateriaSource::MateriaSource(void)
{
	int i = 0;

	while (i < 4)
	{
		this->_invent[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource &m)
{
	int i = 0;

	while (i < 4)
	{
		this->_invent[i] = NULL;
		if (m._invent[i] != NULL)
			this->_invent[i] = m._invent[i]->clone();
		i++;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &m)
{
	if (this != &m)
	{
		int i = 0;

		while (i < 4)
		{
			if (this->_invent[i] != NULL)
				delete (this->_invent[i]);
			this->_invent[i] = NULL;
			if (m._invent[i] != NULL)
				this->_invent[i] = m._invent[i]->clone();
			i++;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_invent[i] == NULL)
		{
			this->_invent[i] = m->clone();
			return;
		}
		i++;
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;

	while (i < 4)
	{
		if (this->_invent[i] != NULL)
		{
			if (this->_invent[i]->getType() == type)
				return (this->_invent[i]->clone());
		}
		i++;
	}
	return (0);
}

MateriaSource::~MateriaSource()
{
	int i = 0;

	while (i < 4)
	{
		if (this->_invent[i] != NULL)
			delete (this->_invent[i]);
		i++;
	}
}