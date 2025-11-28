#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class ScalarConvertor
{
	private:
		ScalarConvertor() = delete;
		ScalarConvertor(const ScalarConvertor& other) = delete;
		ScalarConvertor& operator=(const ScalarConvertor& other) = delete;
		~ScalarConvertor() = delete;
	public:
		static void convert(std::string lit);
};

void toInt()
