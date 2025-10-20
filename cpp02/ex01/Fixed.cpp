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

}

Fixed::Fixed(const float nbr)
{

}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->fixed_point = other.fixed_point;
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

float Fixed::toFloat( void ) const
{

}

int Fixed::toInt( void ) const
{
	
}