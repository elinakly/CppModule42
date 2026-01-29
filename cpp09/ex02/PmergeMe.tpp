#include "PmergeMe.hpp"

size_t comparisons = 0;
template <typename T>
void PmergeMe<T>::parse(int argc, char **argv)
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
        if (std::find(_tempcontainer.begin(), _tempcontainer.end(), value) != _tempcontainer.end())
            throw std::runtime_error("Error: duplicate number: " + s);
        _tempcontainer.push_back(value);
        _container.push_back(value);
    }
}

template <typename T>
T merge(const T& left,const T& right)
{
    T result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())  /// while i < than the end of left string 
                                                //&& j < than the end of right
    {
        if (left[i].first < right[j].first)            //compare i[0] to j[0]
        {
            comparisons++; 
            result.push_back(left[i]); //if i < j push i to result -- so i its result[0]
            i++;
        } 
        else 
        {
            comparisons++; 
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

template <typename T>
T merge_sort(const T& arr) {
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2; //now we have to parts
    T left(arr.begin(), arr.begin() + mid); // 0 to size / 2
    T right(arr.begin() + mid, arr.end()); // size / 2 to the end

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

template <typename T>
T binary_insert_pos(
    T begin,
    T end,
    int value)
{
    auto left = begin;
    auto right = end;

    while (left < right)
    {
        auto mid = left + (right - left) / 2;
        comparisons++;
        if (value < *mid)
            right = mid;
        else
            left = mid + 1;
    }
    return(left);
}

template <typename T>
T final_sort(const T& pend, const T& sorted_main_chain)
{
    T result = sorted_main_chain;
    if (!pend.empty())
        result.insert(result.begin(), pend[0]);
    for (size_t index : Jacobsthal(pend.size())) //jacob return index
    {
        if (index == 0) continue;
        if(index >= pend.size())
            throw "Wrong Jacobsthal index\n";
        int value = pend[index]; // search for valu eon exact jacob index
        auto pos = binary_insert_pos(result.begin(), result.end(), value); //// (binary sort)finds the first element not less than the value
        result.insert(pos, value);  //insert it to exact pos
    }
    return(result);
}

// template <typename T>
// T final_sort(const T& pend, const T& main_chain)
// {
//     T result = main_chain;

//     std::vector<size_t> a_pos(main_chain.size());
//     for (size_t i = 0; i < a_pos.size(); ++i)
//         a_pos[i] = i;
//     result.insert(result.begin(), pend[0]);
//     for (size_t& p : a_pos)
//         ++p;
//     for (size_t index : Jacobsthal(pend.size()))
//     {
//         if (index == 0) continue;
//         if (index >= pend.size())
//             throw "Wrong Jacobsthal index";
//         int b = pend[index];
//         size_t limit = a_pos[index];
//         auto pos = binary_insert_pos(result, result.begin() + limit, b);
//         result.insert(pos, b);
//         for (size_t i = index; i < a_pos.size(); ++i)
//             ++a_pos[i];
//     }

//     return result;
// }

template <typename T>
void PmergeMe<T>::sort_container()
{
    T temp = _container;
    T main_chain; //biggest
    T pend; //smalest
    std::vector<std::pair<int,int>> pairs;
    for(size_t i = 0; i < temp.size() - 1 ; i+=2)
    {
        if (temp[i] > temp[i + 1]) // find biggest and push to A 
        {
            comparisons++; 
            pairs.push_back({temp[i], temp[i + 1]});
        }
        else
        {
            comparisons++;
            pairs.push_back({temp[i+1], temp[i]});
        }
    }
    std::vector<std::pair<int,int>> sorted_main_chain = merge_sort(pairs);
    for(const auto &p : sorted_main_chain)
        main_chain.push_back(p.first);
    for(const auto &p : sorted_main_chain)
        pend.push_back(p.second);
    if(temp.size() % 2 != 0)
        pend.push_back(temp.back()); ///if odd number push to pend
    this->_container = final_sort(pend, main_chain);
}

template <typename T>
void PmergeMe<T>::print_result() const
{
    auto end_it = _tempcontainer.begin() + std::min(_tempcontainer.size(), size_t(10));
    std::cout << "Before: ";
    for(auto i = _tempcontainer.begin(); i < end_it; ++i)
        std::cout << *i << " ";
    if (_tempcontainer.size() > 10)
        std::cout << "[...]";     
    std::cout << "\nAfter: ";
    auto end_it_container = _container.begin() + std::min(_container.size(), size_t(10));
    for(auto i = _container.begin(); i < end_it_container; ++i)
        std::cout << *i << " ";
    if (_tempcontainer.size() > 10)
        std::cout << "[...]";
    std::cout << "\n";
    std::cout << "Comparisons: " << comparisons << "\n";
}
