#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;

    harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("DEBUG");
}