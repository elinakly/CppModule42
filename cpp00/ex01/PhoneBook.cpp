#include "PhoneBook.hpp"

void print_menu()
{
	std::cout << " _________________\n";
	std::cout << "|                 |\n";
	std::cout << "|    PHONEBOOK    |\n";
	std::cout << "|_________________|\n";
	std::cout << "|                 |\n";
	std::cout << "|MAKE YOUR CHOICE |\n";
	std::cout << "|                 |\n";
	std::cout << "|1. ADD           |\n";
	std::cout << "|                 |\n";
	std::cout << "|2. SEARCH        |\n";
	std::cout << "|                 |\n";
	std::cout << "|3. EXIT          |\n";
	std::cout << " =================\n";
}

void PhoneBook::print_index()
{
	std::cout << " ___________________________________________\n";
	std::cout << "|                                           |\n";
	std::cout << "|              LIST OF CONTACTS             |\n";
	std::cout << "|___________________________________________|\n";
	if (saved_contacts == 0)
	{
		std::cout << "| No contacts saved yet.                    |\n";
		std::cout << "|===========================================|\n";
		std::cout << "| PRESS ENTER TO OPEN THE MENU              |\n";
		std::cout << "============================================\n";
		return;
	}
	std::cout << " ___________________________________________\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|----------|----------|----------|----------|\n";
}

void PhoneBook::print_info(int i)
{
	int pos = (index - i + 8) % 8;
	std::cout << "============================================\n";
	std::cout << "| First Name: " << contacts[pos].first_name << std::endl;
	std::cout << "| Last Name: " << contacts[pos].last_name << std::endl;
	std::cout << "| Nickname: " << contacts[pos].nickname << std::endl;
	std::cout << "| Phone Number: " << contacts[pos].phonenumber << std::endl;
	std::cout << "| Darkest Secret: " << contacts[pos].darkest_secret << std::endl;
	std::cout << "============================================\n";
	std::cout << "| PRESS ENTER TO OPEN THE MENU              \n";
	std::cout << "============================================\n";
}

void PhoneBook::phone_number(Contact &contact)
{
	std::string line;
	while (true)
	{
		std::cout << "ENTER PHONE NUMBER: ";
		std::getline(std::cin >> std::ws, line);
		int i = 0;
		while (i < (int)line.length() && std::isdigit(line[i]))
			i++;
		if (i == (int)line.length() && line.length() >= 10 && line.length() <= 15)
		{
			contact.phonenumber = line;
			break;
		}
		else
			std::cout << "Enter a valid phone number (10-15 digits only)\n";
	}
}

void PhoneBook::add_contact()
{
	Contact &contact = contacts[index];
	std::cout << "ENTER FIRST NAME: \n";
	std::getline(std::cin >> std::ws, contact.first_name);
	std::cout << "ENTER LAST NAME: \n";
	std::getline(std::cin >> std::ws, contact.last_name);
	std::cout <<  "ENTER NICKNAME: \n";
	std::getline(std::cin >> std::ws, contact.nickname);
	phone_number(contact);
	std::cout << "ENTER DARKEST SECRET: ";
	std::getline(std::cin >> std::ws, contact.darkest_secret);
	index = (index + 1) % 8;
	if (saved_contacts < 8)
		saved_contacts++;
	std::cout << "===============================\n";
	std::cout << "| NUMBER SAVED -- PRESS ENTER |\n";
	std::cout << "===============================\n";
}   

void truncate_and_print(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

void PhoneBook::search()
{
	std::string input;
	print_index();
	if (saved_contacts == 0)
		return;
	for (int i = 0; i < saved_contacts; i++)
	{
		int pos = (index - 1 - i + 8) % 8;
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		truncate_and_print(contacts[pos].first_name);
		std::cout << "|";
		truncate_and_print(contacts[pos].last_name);
		std::cout << "|";
		truncate_and_print(contacts[pos].nickname);
		std::cout << "|\n";
	}
	std::cout << "| PRESS INDEX TO SEE ADDITIONAL INFO        |\n";
	std::cout << "| PRESS ENTER TO OPEN THE MENU              |\n";
	std::cout << "============================================\n";
	std::getline(std::cin, input);
	int i = std::atoi(input.c_str()); //use c_str because atoi func accept const char* not std::string
	if (i < 1 || i > saved_contacts)
	{
		std::cout << "Invalid index.\n";
		print_menu();
		return;
	}
	print_info(i);
}
