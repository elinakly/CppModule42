#include <string>
#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Address of string: " << &string << std::endl;
    std::cout << "Address stored in ptr: " << stringPTR << std::endl;
    std::cout << "Address of ref: " << &stringREF << std::endl;

    std::cout << "===============================" << std::endl;

    std::cout << "Value of string: " << string << std::endl;
    std::cout << "Value via ptr: " << *stringPTR << std::endl;
    std::cout << "Value via ref: " << stringREF << std::endl;
    return(0);
}