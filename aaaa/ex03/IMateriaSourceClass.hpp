#ifndef IMATERIASOURCECLASS_HPP
#define IMATERIASOURCECLASS_HPP

#include <iostream>
#include "AMateriaClass.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}                                  //[required]
        virtual void learnMateria(AMateria *) = 0;                    //[required]
        virtual AMateria *createMateria(std::string const &type) = 0; //[required]
};

#endif