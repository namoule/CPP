#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int Contact::index = 0;

Contact::Contact()
{
    index++;
    if(this->index > 7)
        this->index = 0;
}

Contact::~Contact()
{
}

