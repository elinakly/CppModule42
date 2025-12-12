#include "iter.hpp"

void print(const int& x)
{
    std::cout << x << " ";
}

void increment(int& x)
{
    x += 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    
    std::cout << "Before increment: ";
    iter(arr, 4, print);
    std::cout << "\n";
    
    iter(arr, 4, increment);
    
    std::cout << "After increment: ";
    iter(arr, 4, print);
    std::cout << "\n";

    return 0;
}