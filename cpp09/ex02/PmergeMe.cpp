#include "PmergeMe.hpp"

void PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        size_t pos;
        int value;
        try {
            value = std::stoi(s, &pos);
        } catch (...) {
            throw std::runtime_error("Error: non valid value: " + s);
        }
        if (pos != s.length())
            throw std::runtime_error("Error: non valid value: " + s);
        if (value < 0)
            throw std::runtime_error("Error: negative value: " + s);
        if (std::find(_tempvec.begin(), _tempvec.end(), value) != _tempvec.end())
            throw std::runtime_error("Error: duplicate number: " + s);
        _tempvec.push_back(value);
        _vec.push_back(value);
        _deq.push_back(value);
    }
}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())  /// while i < than the end of left string 
                                                //&& j < than the end of right
    {
        if (left[i] < right[j])            //compare i[0] to j[0]
        {
            result.push_back(left[i]); //if i < j push i to result -- so i its result[0]
            i++;
        } 
        else 
        {
            result.push_back(right[j]); //else push j  to result
            j++;
        }
    }
    while (i < left.size()) //if we run out of elements in j,
        result.push_back(left[i++]); // but i has something left just push to result
    while (j < right.size())
        result.push_back(right[j++]);
    return result;
}

std::vector<int> merge_sort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2; //now we have to parts
    std::vector<int> left(arr.begin(), arr.begin() + mid); // 0 to size / 2
    std::vector<int> right(arr.begin() + mid, arr.end()); // size / 2 to the end

    left = merge_sort(left); // recursion to separate up to 1 number in left part
    right = merge_sort(right); // recursion to separate up to 1 number in right part

    return merge(left, right); //compair parts
}

std::vector<size_t> Jacobsthal(size_t n) //jac numbers are 0 1 1 3 5 ..
{
    std::vector<size_t> jac;
    std::vector<size_t> order;

    jac.push_back(1); // We start from J(3) because the first two pend elements doest work for us(0 && 1(dup))
    jac.push_back(3);//we start from 2 elem in vect bc we need it in next line
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);  //J(k) = J(k−1) + 2·J(k−2)
                        // so like push_back((jac[last_elem] + 2 * jac[second_last]))
                        //first iter : push_back(3 + 2 * 1);
                        //push_back(5); etc 
    // std::cout << "jacobs: ";
    // for(auto it = jac.begin(); it < jac.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    size_t prev = 0;
    for (size_t j : jac) //take each number from jac
    {
        size_t end = std::min(j, n); //jac can be bigger than pend.size()
        for (size_t i = end; i > prev; --i) //put it in order so its like 0 2 1 etc
            order.push_back(i - 1);
        prev = end;
    }
    // std::cout << "order: ";
    // for(auto it = order.begin(); it < order.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    return order;
}

std::vector<int> final_sort(const std::vector<int>& pend, std::vector<int>& sorted_main_chain)
{
    std::vector<int> result = sorted_main_chain;
    for (size_t index : Jacobsthal(pend.size())) //jacob return index
    {
        if(index >= pend.size())
            throw "Wrong Jacobsthal index\n";
        int value = pend[index]; // search for valu eon exact jacob index
        auto pos = std::lower_bound(result.begin(), result.end(), value); //// (binary sort)finds the first element not less than the value
        result.insert(pos, value);  //insert it to exact pos
    }
    return(result);
}

void PmergeMe::sort_vec()
{
    std::vector<int> temp = _vec;
    std::vector<int> main_chain; //biggest
    std::vector<int> pend; //smalest
    for(size_t i = 0; i < temp.size() - 1 ; i+=2)
    {
        if (temp[i] > temp[i + 1]) // find biggest and push to A
        {    
            main_chain.push_back(temp[i]);
            pend.push_back(temp[i + 1]);
        }
        else
        {
            main_chain.push_back(temp[i + 1]);
            pend.push_back(temp[i]);
        }
    }
    if(temp.size() % 2 != 0)
        pend.push_back(temp.back()); ///if odd number push to pend
    std::vector<int> sorted_main_chain = merge_sort(main_chain);
    this->_vec = final_sort(pend, sorted_main_chain);
}

// void PmergeMe::sort_deq()
// {

// }

void PmergeMe::print_result() const
{
    auto end_it = _tempvec.begin() + std::min(_tempvec.size(), size_t(10));
    std::cout << "Before: ";
    for(auto i = _tempvec.begin(); i < end_it; ++i)
        std::cout << *i << " ";
    if (_tempvec.size() > 10)
        std::cout << "[...]";     
    std::cout << "\nAfter: ";
    auto end_it_vec = _vec.begin() + std::min(_vec.size(), size_t(10));
    for(auto i = _vec.begin(); i < end_it_vec; ++i)
        std::cout << *i << " ";
    if (_tempvec.size() > 10)
        std::cout << "[...]\n"; 
}
