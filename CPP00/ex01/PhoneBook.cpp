#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <cstring>
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
    if(contacts[index].setPhoneNumber(pn) == -1)
    {
        std::cout << "invalid phone number" << std::endl;
        return(0);
    }
    contacts[index].setDarkestSecret(ds);
    index++;
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
    char val;
    std::cout << "please enter a value between 1 and 8 (included): " << std:: endl;
    std::cin >> val;
    if(val <= '0' || val >= '9')
        std::cout << "invalid value, please try again later." << std::endl;
    else
    {
        int value = (val - '0') -1;
        std::cout << "value : " << value << std::endl;
        std::cout << "First name : [" << contacts[value].first_name << "]." << std::endl;
        std::cout << "Last name : [" << contacts[value].last_name << "]." << std::endl;
        std::cout << "Nickname : [" << contacts[value].nickname << "]." << std::endl;
        std::cout << "Phone number : [" << contacts[value].phone_number << "]." << std::endl;
        std::cout << "Darkest secret : [" << contacts[value].darkest_secret << "]." << std::endl;
    }
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
    std::cout << "What is your request?"<< std::endl<< "Enter your order:";
    std::cin >> commande;
    if (std::cin.eof()) 
    {
        std::cout << "\nEnd of entry (Ctrl+D detected)." << std::endl;
        return -42;
    }
    return(check_commandes(commande));
}

PhoneBook::PhoneBook(void)
{
    std::cout << "Welcome to your Phonebook"<< std::endl;
    while(command_input() != -42)
    exit_phonebook();
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Thank you for your visit!"<<std::endl;
}

int main(void)
{
    PhoneBook book;
    return(0);
}