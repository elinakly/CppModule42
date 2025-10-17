#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for me 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe addding extra bacon costs more money. You didn`t put enough bacon in my burger! If you did, I wouln`t be asking for more!\n\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I`ve been coming for years whereas you started working here since last month\n\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the maneger now.\n";
}


void Harl::complain(std::string level)
{
    std::string options[4] = {"DEBAG", "INFO", "WARNING", "ERROR"};
    int N = get_level(level);
    void(Harl::*comments[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    switch(N)
    {
        case 0: 
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            for (int i = N - 1; i < 4; i++)   //-1 because N starts with 1
                (this->*comments[i])();
            break;
    }
}