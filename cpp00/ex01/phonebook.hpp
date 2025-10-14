#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> 

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
	};

	class PhoneBook
	{
	private:
		static	const int MaxContacts = 8;
		Contact	contacts[MaxContacts];
		int		index = 0;
		int		saved_contacts = 0;
	public:
		void	phone_number(Contact &contact);
		void	add_contact();
		void	search();
		void	print_index();
		void	print_info(int i);
};

void print_menu();

#endif