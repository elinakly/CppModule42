#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
        return(std::cerr << "Wrong usage of arguments <./program name> <polish notation>\n", 1);
    if(!valid_input(argv[1]))
        return(1);
}