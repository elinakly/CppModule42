#include "Span.hpp"

Span::Span(unsigned int size) : _size(size)
{
    arr.reserve(size); //set /capacity to (int size), and .size to 0
}

Span::Span(const Span& other) : _size(other._size), arr(other.arr)
{
}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        this->_size = other._size;
        this->arr = other.arr;
    }
    return(*this);
}


void Span::addNumber(int Number)
{
    if(arr.size() < _size)
        arr.push_back(Number);
    else
        throw VectorIsFull();
}

int Span::shortestSpan() const
{
    if(arr.size() < 2)
        throw NotEnoughElement();
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for(auto iter = sorted.begin() + 1; iter != sorted.end() - 1 ; ++iter) //preincrement is efficienter for iter
    {
        int diff = *iter - *(iter - 1);
        if (minSpan > diff)
            minSpan = diff;
    }
    return(minSpan);
}

int Span::longestSpan() const
{
    if(arr.size() < 2)
        throw NotEnoughElement();
    auto [minIt, maxIt] = std::minmax_element(arr.begin(), arr.end());
    return *maxIt - *minIt;
}

const char* Span::NotEnoughElement::what() const noexcept
{
    return("Vector has not enough elements\n");
}

const char* Span::VectorIsFull::what() const noexcept
{
    return("Vector is FUll!!\n");
}