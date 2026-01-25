#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <chrono>
class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::vector<int> _tempvec;
        std::deque<int> _deq;
    public:
        PmergeMe() = default;
        PmergeMe(const PmergeMe& other) = default;
        ~PmergeMe() = default;
        PmergeMe & operator=(const PmergeMe& other) = default;
        void parse(int argc, char **argv);
        void sort_vec();
        // void sort_deq(std::deque<int> &deq);
        void print_result() const;
    };
