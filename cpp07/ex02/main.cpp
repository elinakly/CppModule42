#include <iostream>

#include "Array.hpp"

int main(int, char**)
{
    std::cout << "--- default constructor ---\n";
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;
    try {
        arr1[0] = 42; // should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- insigned int constructor ---\n";
    Array<int> arr2(5);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 10;

    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;

    std::cout << "\n--- copy constructor ---\n";
    Array<int> arr3 = arr2;
    arr3[0] = 100;
    std::cout << "arr2[0] = " << arr2[0] << ", arr3[0] = " << arr3[0] << std::endl;

    std::cout << "\n--- copy assignment ---\n";
    Array<int> arr4;
    arr4 = arr2;
    arr4[1] = 200;
    std::cout << "arr2[1] = " << arr2[1] << ", arr4[1] = " << arr4[1] << std::endl;

    std::cout << "\n--- const array ---\n";
    const Array<int> constArr(2);
    try {
        std::cout << "constArr[0] = " << constArr[0] << std::endl;
        // constArr[0] = 10; //  not compile
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- out-of-bounds ---\n";
    try {
        arr2[10] = 5; // should throw --- arr2(5) has 5 elements
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}