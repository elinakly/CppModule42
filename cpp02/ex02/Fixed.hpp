#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point;
		static const int nbr_bit = 8;
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& other);
		~Fixed();

		Fixed& operator=(const Fixed& other);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed& 			min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& 	min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& 			max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& 	max(const Fixed& fixed1, const Fixed& fixed2);
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif