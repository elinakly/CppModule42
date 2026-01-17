#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
        return(std::cerr << "Error: Wrong argument usage [./program_name] [input file].\n", 1);
    if(!file_pasing(argv[1]))
        return(1);
}