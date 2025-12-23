#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string lit)
{
	switch(getType(lit))
	{
		case 1:
			convertPseudo(lit);
			break;
		case 2:
			convertChar(lit);
			break;
		case 3:
			convertFloat(lit);
			break;
		case 4:
			convertDouble(lit);
			break;
		case 5:
			convertInt(lit);
			break;
		default:
			std::cout << "Invalid input\n";
			break;
	}
}