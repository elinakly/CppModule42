#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if(argc != 3)
		std::cout << "To run a program do [./convert] [literal]\n";
	ScalarConvertor::convert(argv[2]);
}
