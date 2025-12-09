#include "ScalarConverter.hpp"


void convertPseudo(std::string lit)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (lit == "nan" || lit == "nanf")
	{
		std::cout << "Float: nanf\n";
		std::cout << "Double: nan\n";
	}
	else if (lit == "+inf" || lit == "+inff")
	{
		std::cout << "Float: +inff\n";
		std::cout << "Double: +inf\n";
	}
	else if (lit == "-inf" || lit == "-inff")
	{
		std::cout << "Float: -inff\n";
		std::cout << "Double: -inf\n";
	}
}

void printCharValue(double value)
{
    std::cout << "char: ";
    if (value < 0 || value > 255)
        std::cout << "impossible\n";
    else if (!isprint(static_cast<int>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
}

void convertChar(std::string lit)
{
	printCharValue(lit[0]); 
	std::cout << "int: " << static_cast<int>(lit[0]) << "\n";
	std::cout << "float: " << static_cast<float>(lit[0]) << ".0f\n";
	std::cout << "double: " << static_cast<double>(lit[0]) << ".0\n";
}

void convertFloat(std::string lit)
{
	lit.pop_back(); // remove 'f'
	try
	{
		float value = std::stof(lit);
		printCharValue(value); 
		std::cout << "int: " << static_cast<int>(value) << "\n";
		std::cout << "float: " << value << "\n";
		std::cout << "double: " << static_cast<double>(value) << ".0\n";
	} 
	catch (std::invalid_argument& e) 
	{
		std::cout << "Not a valid number\n";
	} 
	catch (std::out_of_range& e)
	{
		std::cout << "Number out of float range\n";
	}
}

void convertDouble(std::string lit)
{
	try
	{
		double value = std::stod(lit);
		printCharValue(value); 
		std::cout << "int: " << static_cast<int>(value) << "\n";
		std::cout << "float: " << static_cast<float>(value) << ".0f\n";
		std::cout << "double: " << value << "\n";
	} 
	catch (std::invalid_argument& e) 
	{
		std::cout << "Not a valid number\n";
	} 
	catch (std::out_of_range& e)
	{
		std::cout << "Number out of double range\n";
	}
}

void convertInt(std::string lit)
{
	try
	{
		int value = std::stoi(lit);
		printCharValue(value); 
		std::cout << "int: " << value << "\n";
		std::cout << "float: " << static_cast<float>(value) << ".0f\n";
		std::cout << "double: " << static_cast<double>(value) << ".0\n";
	} 
	catch (std::invalid_argument& e) 
	{
		std::cout << "Not a valid number\n";
	} 
	catch (std::out_of_range& e)
	{
		std::cout << "Number out of int range\n";
	}
}

bool isfloat(std::string lit)
{
	size_t start = 0;
	if(lit[0] == '-' || lit[0] == '+')
		start = 1;
	bool legit = false;
	for(size_t i = start; i < lit.length() - 1 ; i++)
	{
		if(isdigit(lit[i]))
			legit = true;
		else if(lit[i] != '.')
			return(false);
	}
	return(legit);
}

bool isdouble(std::string lit)
{
	size_t start = 0;
	if(lit[0] == '-' || lit[0] == '+')
		start = 1;
	bool legit = false;
	for(size_t i = start; i < lit.length() -1 ; i++)
	{
		if(isdigit(lit[i]))
			legit = true;
		else if(lit[i] != '.')
			return(false);
	}
	return(legit);
}

bool isint(std::string lit)
{
	size_t start = 0;
	if(lit[0] == '-' || lit[0] == '+')
		start = 1;
	for(size_t i = start; i < lit.length(); i++)
	{
		if(!isdigit(lit[i]))
			return(false);
	}
	return(true);
}

int getType(std::string lit)
{
	size_t dotcount = std::count(lit.begin(), lit.end(), '.');
	if(dotcount > 1)
		return(6);
	if (lit == "nanf" || lit == "-inff" || lit == "+inff" || lit == "-inf" || lit == "+inf" || lit == "nan")
		return(1);
	else if (lit.length() == 1 && !isdigit(lit[0]))
		return(2);
	else if (isfloat(lit) && lit.back() == 'f' && dotcount == 1)
		return(3);
	else if (isdouble(lit) && dotcount == 1)
		return(4);
	else if (isint(lit) && dotcount == 0)
		return(5);
	return(6);
}

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