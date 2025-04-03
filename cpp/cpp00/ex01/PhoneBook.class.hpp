#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class PhoneBook {
public:
    Contact contacts[Contact::max_contacts]; // Tableau de contacts
    int current_index; // Indice du contact actuel ajouté

    PhoneBook(); // Constructeur
    ~PhoneBook(); // Destructeur

    int add(); // Ajoute un contact
    int search(); // Recherche et affiche les contacts
    int exit_phonebook(); // Quitte le programme
    int wrong_input(); // Gestion des mauvaises entrées
    int check_commandes(char *commande); // Vérifie les commandes
    int command_input(); // Récupère l'entrée de commande de l'utilisateur
    int error(char *mess_err); // Affiche un message d'erreur
    static int index;
};

#endif // PHONEBOOK_CLASS_HPP
