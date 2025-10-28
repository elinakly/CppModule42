#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> 

class Contact
{
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
	public :
		std::string get_first() {return first_name; }
		std::string	get_last() {return last_name; }
		std::string	get_nick() {return nickname; }
		std::string	get_phone() {return phonenumber; }
		std::string	get_dark() {return darkest_secret; }
		void set_first(const std::string &value) { first_name = value; }
		void set_last(const std::string &value) { last_name = value; }
		void set_nick(const std::string &value) { nickname = value; }
		void set_dark(const std::string &value) { darkest_secret = value; }
		void set_phone(const std::string &value) { phonenumber = value; }

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