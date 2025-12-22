#include "easyfind.hpp"

template <typename T>
auto easyfind(T& arr, int tofind)
{
    auto it{std::find(std::begin(arr), std::end(arr), tofind)};
    if (it == arr.end())
        throw std::exception();
    return(it);
}