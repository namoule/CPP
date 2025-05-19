#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {
public:
    Contact contacts[Contact::max_contacts];
    int current_index;

    PhoneBook();
    ~PhoneBook();

    int add();
    int search(); 
    int exit_phonebook(); 
    int wrong_input();
    int check_commandes(char *commande);
    int command_input();
    int error(char *mess_err);
    static int index;
};

#endif 
