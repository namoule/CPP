#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iomanip>
int PhoneBook::index = 0;

int PhoneBook::error(char *mess_err)
{
    std::cout<< "Error : "<<mess_err<<"!\n"<<std::endl;
    return(1);
}



int PhoneBook::add()
{
    std::string fn, ln, nm, pn, ds;

    if(index >= 8)
        index = 0;
    std::cout<< "First name :";
    std::cin >> fn;
    std::cout<< "last name :";
    std::cin >> ln;
    std::cout<< "Nickname :";
    std::cin >> nm;
    std::cout<< "Phone Number :";
    std::cin >> pn;
    std::cout<< "Darkest secret : ";
    std::cin >> ds;
    contacts[index].setFirstName(fn);
    contacts[index].setLastName(ln);
    contacts[index].setNickname(nm);
    contacts[index].setPhoneNumber(pn);
    contacts[index].setDarkestSecret(ds);
    index++;
    std::cout <<index << std::endl;
    return(0);
}

int PhoneBook::search()
{
    int i  = 0;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "|     Index | First Name | Last Name | Nickname  |" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    while(i < 8) {
        std::cout << "| " << std::setw(10) << i + 1;

        std::string first_name = contacts[i].first_name;
        if (first_name.length() > 9) first_name = first_name.substr(0, 9) + ".";
        std::cout << "| " << std::setw(10) << first_name;

        std::string last_name = contacts[i].last_name;
        if (last_name.length() > 9) last_name = last_name.substr(0, 9) + ".";
        std::cout << "| " << std::setw(10) << last_name;

        std::string nickname = contacts[i].nickname;
        if (nickname.length() > 9) nickname = nickname.substr(0, 9) + ".";
        std::cout << "| " << std::setw(10) << nickname;
        std::cout << " |" << std::endl;
        i++;
    }

    std::cout << "--------------------------------------------------" << std::endl;
    return 0;
}

int PhoneBook::exit_phonebook()
{
    return(0);
}

int PhoneBook::wrong_input()
{
    error((char*)"Wrong input: Only [ADD], [SEARCH], [EXIT]");
    return(0);
}

int PhoneBook::check_commandes(char *commande)
{
    if(strcmp(commande, "ADD") == 0)
        return(add(), 0);
    else if(strcmp(commande, "SEARCH") == 0)
        return(search());
    else if(strcmp(commande, "EXIT") == 0)
        return(-42);
    else
        return(wrong_input(), 0);
    return -1;
}

int PhoneBook::command_input()
{
    char commande[512];
    std::cout << "Quelle est votre demande ?"<< std::endl<< "Entrez votre commande : ";
    std::cin >> commande;
    if (std::cin.eof()) 
    {
        std::cout << "\nFin de l'entrée (Ctrl+D détecté)." << std::endl;
        return -42;
    }
    return(check_commandes(commande));
}

PhoneBook::PhoneBook(void)
{
    std::cout << "Bienvenue dans votre Phonebook"<< std::endl;
    while(command_input() != -42)
    exit_phonebook();
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Merci de votre visite !"<<std::endl;
}

int main(void)
{
    PhoneBook book;
    return(0);
}