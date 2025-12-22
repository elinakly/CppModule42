#include "easyfind.hpp"

int main()
{
    try{
        std::vector<int> a = {4, 1, 5, 5};
        auto it =  easyfind(a, 5);
        std::cout << *it << " was found at " << &(*it) << "\n";
    }catch(std::exception &e)
    {
        std::cout << "Match not found\n";
    }
    return(0);
}