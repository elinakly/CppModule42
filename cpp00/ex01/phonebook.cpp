#include "phonebook.hpp"

void print_menu()
{
    std::cout << " _________________\n";
    std::cout << "|                 |\n";    
    std::cout << "|    PHONEBOOK    |\n";
    std::cout << "|_________________|\n";
    std::cout << "|                 |\n";    
    std::cout << "|MAKE YOUR CHOICE |\n";
    std::cout << "|                 |\n";    
    std::cout << "|1. ADD CONTACT   |\n";
    std::cout << "|                 |\n";    
    std::cout << "|2. SEARCH        |\n";
    std::cout << "|                 |\n";    
    std::cout << "|3. EXIT          |\n";
    std::cout << "==================\n";
}

void PhoneBook::add_contact()
{
    std::string line;
    Contact &contact = contacts[index];
    std::cout << "ENTER FIRST NAME: \n";
    std::getline(std::cin >> std::ws, contact.first_name); 
    std::cout << "ENTER LAST NAME: \n";
    std::getline(std::cin >> std::ws, contact.last_name); 
    std::cout <<  "ENTER NICKNAME: \n";
    std::getline(std::cin >> std::ws, contact.nickname); 
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
    std::cout << "ENTER DARKEST SECRET: ";
    std::getline(std::cin >> std::ws, contact.darkest_secret); // wc to skip whitespaces
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
    std::cout << " ___________________________________________\n";
    std::cout << "|                                           |\n";
    std::cout << "|              LIST OF CONTACTS             |\n";
    std::cout << "|___________________________________________|\n";
    if (saved_contacts == 0)
    {
        std::cout << "| No contacts saved yet.                   |\n";
        std::cout << "|                                          |\n";
        std::cout << "| PRESS ENTER TO OPEN THE MENU             |\n";
        std::cout << "===========================================\n";
        return;
    }
    std::cout << " ___________________________________________\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "|----------|----------|----------|----------|\n";

    int total = saved_contacts;
    for (int i = 0; i < total; i++)
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
    std::cout << "| PRESS ENTER TO OPEN THE MENU             |\n";
    std::cout << "===========================================\n";

    std::string input;
    std::getline(std::cin, input);
    int i = std::atoi(input.c_str());

    if (i < 1 || i > saved_contacts)
    {
        std::cout << "Invalid index.\n";
        print_menu();
        return;
    }

    int pos = (index - i + 8) % 8;
    std::cout << "============================================\n";
    std::cout << "| First Name: " << contacts[pos].first_name << std::endl;
    std::cout << "| Last Name: " << contacts[pos].last_name << std::endl;
    std::cout << "| Nickname: " << contacts[pos].nickname << std::endl;
    std::cout << "| Phone Number: " << contacts[pos].phonenumber << std::endl;
    std::cout << "| Darkest Secret: " << contacts[pos].darkest_secret << std::endl;
    std::cout << "============================================\n";
}

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
        if (line == "1")
            phonebook.add_contact();
        else if (line == "2")
            phonebook.search();
        else if (line == "3")
            break;
        else 
            print_menu();
    }
    return(0);
}