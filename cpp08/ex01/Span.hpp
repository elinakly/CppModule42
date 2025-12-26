#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime> 

class Span
{
    private:
        unsigned int _size;
        std::vector<int> arr;
    public:
        Span(unsigned int size);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span() = default;

        void addNumber(int Number);
        int shortestSpan() const;
        int longestSpan() const;
        void printContaner() const;
        template <typename Iter>
        void addNumbers(Iter begin, Iter end)
        {
            for(; begin != end; ++begin)
                this->addNumber(*begin);
        }
        class NotEnoughElement: public std::exception
        {
            const char* what() const noexcept;
        };
        class VectorIsFull: public std::exception
        {
            const char* what() const noexcept;
        };
};