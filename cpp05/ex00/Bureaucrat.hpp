#pragma once

#include <string>
#include <iostream>

class Bureucrat
{
	private:
		std::string  name;
		unsigned int grade;
	public:
		Bureucrat(std::string  name, unsigned int grade);
		Bureucrat(const Bureucrat& other);
		~Bureucrat();

		Bureucrat& operator=(const Bureucrat& other);
		unsigned int  operator>>(const Bureucrat& other);

		void GradeTooHighException();
		void GradeTooLowException();
		std::string getName();
		unsigned int getGrade();
		void IncrementGrade(int grade);
		void DicrementGrade(int grade);
};