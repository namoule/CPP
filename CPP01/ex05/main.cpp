#include "Harl.hpp"

int	main(void)
{
	Harl	harl;
    
	harl.complain("invalid");

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}