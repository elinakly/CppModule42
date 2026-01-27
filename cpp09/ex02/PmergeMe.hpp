#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip> 

template<typename T>
class PmergeMe
{
    private:
        T _container;
        T _tempcontainer;
    public:
        PmergeMe() = default;
        PmergeMe(const PmergeMe& other) = default;
        ~PmergeMe() = default;
        PmergeMe & operator=(const PmergeMe& other) = default;
        void parse(int argc, char **argv);
        void sort_container();
        void print_result() const;
};

#include "PmergeMe.tpp"