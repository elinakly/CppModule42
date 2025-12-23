#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <cfloat>
#include <climits>

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
	public:
		static void convert(std::string lit);
};

void convertPseudo(std::string lit);
void printCharValue(double value);
void convertChar(std::string lit);
void convertFloat(std::string lit);
void convertDouble(std::string lit);
void convertInt(std::string lit);
bool isfloat(std::string lit);
bool isdouble(std::string lit);
bool isint(std::string lit);
int getType(std::string lit);