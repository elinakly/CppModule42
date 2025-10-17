#include "Harl.hpp"

int get_level(std::string level)
{
    int i = 0;
    if (level == "DEBUG")
        i = 1;
    else if (level == "INFO")
        i = 2;
    else if (level == "WARNING")
        i = 3;
    else if (level == "ERROR")
        i = 4;
    return(i);
}

int main(int argc, char *argv[])
{
    Harl harl;

    if(argc != 2)
        return(1);
    harl.complain(std::string(argv[1]));
    return(0);
}