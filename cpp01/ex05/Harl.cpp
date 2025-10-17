#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for me 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe addding extra bacon costs more money. You didn`t put enough bacon in my burger! If you did, I wouln`t be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I`ve been coming for years whereas you started working here since last month\n";
}

void Harl::error()
{
     std::cout << "This is unacceptable! I want to speak to the maneger now.\n";
}

void Harl::complain(std::string level)
{
    std::string options[4] = {"DEBAG", "INFO", "WARNING", "ERROR"};

    void(Harl::*comments[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if(level == options[i])
        {
            (this->*comments[i])();
            return;
        }
    }
}
