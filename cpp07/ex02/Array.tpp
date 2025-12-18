#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), arr{nullptr} //<T> let the constructor knows witch exactly class to init -- in main -- Array<int> a; (in this case class with template <T>) 
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), arr(nullptr)
{
    try
    {
        arr = new T[n];
    }
    catch (const std::bad_alloc&)
    {
        _size = 0;
        throw;
    }
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), arr(nullptr)
{
    if (_size > 0)
    {
        arr = new T[_size];
        for (size_t i = 0; i < _size; i++)
            arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const  Array<T>&  other)
{
    if (this != &other)
    {
        if(arr)
            delete[] arr;
        this->_size = other._size;
        if(_size > 0)
        {
            arr = new T[_size];
            for(unsigned int i = 0; i < _size; i++)
                arr[i] = other.arr[i];
        }
    }
    return(*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) // every method that return a pointer must have const and non const version(STL)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];    
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return arr[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
size_t Array<T>::size() const
{
    return(_size);
}


