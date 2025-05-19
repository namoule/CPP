// Contact.class.hpp
#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Contact {
    public:
    std::string first_name;   
    std::string last_name;  
    std::string nickname;   
    std::string phone_number;
    std::string darkest_secret; 
    
    static const int max_contacts = 8;
    static int index;
    
    Contact();
    
    ~Contact();
    
    void setFirstName(const std::string &fn) { first_name = fn; }
    void setLastName(const std::string &ln) { last_name = ln; }
    void setNickname(const std::string &nm) { nickname = nm; }
    void setPhoneNumber(const std::string &pn) { phone_number = pn; }
    void setDarkestSecret(const std::string &ds) { darkest_secret = ds; }
    
    void displayContactInfo() const {
        std::cout << "|" << first_name << "|" << last_name << "|" << nickname << "|" << std::endl;
    }
    
    void displayFullContact() const {
        std::cout << "First Name: " << first_name << std::endl;
        std::cout << "Last Name: " << last_name << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Phone Number: " << phone_number << std::endl;
        std::cout << "Darkest Secret: " << darkest_secret << std::endl;
    }
};


#endif