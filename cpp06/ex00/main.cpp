#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{	
		std::cout << "To run a program do [./convert] [literal]\n";
		return(1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}
