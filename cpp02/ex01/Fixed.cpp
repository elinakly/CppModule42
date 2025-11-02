#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	fixed_point = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called\n";
	fixed_point = nbr << nbr_bit; // from int to fixed.../ multiplies nbr by 2^nbr_bit
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called\n";
	// shift the fractional part into int, roundf() to round to closest integer
	fixed_point = (roundf(nbr * (1 << nbr_bit))); // from float to fixed
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->fixed_point = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->fixed_point = other.getRawBits();
	return(*this);

}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return(fixed_point);
}


void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	fixed_point = raw;
}

float Fixed::toFloat( void ) const //from fixed to float
{
	return static_cast<float>(fixed_point) / (1 << nbr_bit); //static_cast<float> -- saverthan (float) shifts 1 left by the number of fractional bits (e.g., 1 << 8 = 256).
}

int Fixed::toInt( void ) const //from fixed to int
{
	return fixed_point >> nbr_bit;  //shift right to drop the fractional bits
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat(); //we use to_float to see real value of my fixed_point 
	return(out);
}