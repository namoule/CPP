#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Alice", 1);
        Bureaucrat intern("Bob", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Ford");

        std::cout << "\n--- Tentative de signature ---\n";
        intern.signAForm(shrub);
        boss.signAForm(shrub);

        std::cout << "\n--- Tentative d'exécution ---\n";
        shrub.execute(boss);

        std::cout << "\n--- Robotomisation multiple ---\n";
        boss.signAForm(robot);
        for (int i = 0; i < 5; i++) {
            robot.execute(boss);
        }

        std::cout << "\n--- Pardon présidentiel ---\n";
        boss.signAForm(pardon);
        pardon.execute(boss);

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}