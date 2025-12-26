#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        MutantStack() = default;
        MutantStack(const MutantStack& other) = default;
        MutantStack& operator=(const MutantStack& other) = default;
        ~MutantStack() = default;

        //using -- type alias
        using iterator = typename std::stack<T>::container_type::iterator; //“iterator of the container inside the stack”
                                                                          // we use using to use "iterator" as a template, so we dont ned to write the whole template everytime
                                                                          //stack is not a container its adapter that use a deque container by default
                                                                          //contaner_type -- it just defenision for container
                                                                          // std::stack<T>::contaner_type -- actual underlying container (std::deque<T> by default).
        using const_iterator = typename std::stack<T>::container_type::const_iterator;

        iterator begin() { return this->c.begin(); } //c -- (Container c) -- its deque by default
        iterator end()   { return this->c.end(); }
};