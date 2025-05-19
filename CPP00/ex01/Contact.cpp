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
int Contact::setPhoneNumber(const std::string &pn)
{
    int i = 0;
    while(pn[i])
    {
        if(pn[i] < '0' || pn[i] > '9')
        {
            std::cout << "Phone number set to 0000000000 because not valid." << std::endl;
            this->phone_number = "0000000000";
            return(-1);
        }i++;
    }
    if(i == 10)
        this->phone_number = pn;
    else
        std::cout << "Invlid phone number." << std::endl;
    return(0);
}
