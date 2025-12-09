#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <algorithm>

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
