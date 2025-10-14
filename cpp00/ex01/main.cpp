#include "phonebook.hpp"

int main(int ac, char *ag[])
{
	PhoneBook phonebook;
	std::string line;
	(void)ag;
	if(ac != 1)
		return(1);
	print_menu();
	while (std::getline(std::cin, line))
	{
		if (line == "ADD")
			phonebook.add_contact();
		else if (line == "SEARCH")
			phonebook.search();
		else if (line == "EXIT")
			break;
		else
			print_menu();
	}
	return(0);
}