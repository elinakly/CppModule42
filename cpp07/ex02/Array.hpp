#pragma once
#include <ctime>
# include <exception>
#include <iostream>
#include <string>
template <typename T>

class Array
{
	private:
		size_t _size;
		T* arr;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const  Array<T>&  other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const; 
		size_t size() const;
};

#include "Array.tpp"