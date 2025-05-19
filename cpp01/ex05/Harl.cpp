#include "Harl.hpp"


Harl::Harl()
{
}
Harl::~Harl()
{
}
void	Harl::debug(void) const
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

int	getCommand(std::string Command)
{
	const std::string	Commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					CommandNumber = 4;

	int i = 0;
    while(i < 4 && CommandNumber == 4)
	{
		if (Command == Commands[i])
			CommandNumber = i;
        i++;
	}
	return (CommandNumber);
}

void	Harl::complain(std::string Command) const
{
	const function_p	complains[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int					CommandNumber = getCommand(Command);

	if (CommandNumber < 4)
		(this->*(complains[CommandNumber]))();
	else
		std::cout << "Invalid Command. Try again." << std::endl << std::endl;
}