#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    int i = std::rand() % 3;
    switch(i)
    {
        case 0:
            std::cout << "instantiate A\n";
            return(new A);
        case 1:
            std::cout << "instantiate B\n";
            return(new B);
        default:
            std::cout << "instantiate C\n";
            return(new C);
    }
}

void identify(Base* p) //if we cast to pointer cast throws an exception "nullptr"
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) //if we cast to reff cast throws an exception "bad cast"
{
    {
        try
        { 
            dynamic_cast<A&>(p); std::cout << "A\n";
            return;
        } 
        catch (std::bad_cast& e) 
        {
        }
    }

    {    
        try
        { 
            dynamic_cast<B&>(p); std::cout << "B\n";
            return;
        } 
        catch (std::bad_cast& e) 
        {
        }
    }
    {
        try
        { 
            dynamic_cast<C&>(p); std::cout << "C\n";
            return;
        } 
        catch (std::bad_cast& e) 
        {
        }
    }
    std::cout << "Unknown type\n";
}


int main()
{
    std::srand(std::time(nullptr));
    Base* p = generate();
    identify(p);
    identify(*p);
    delete(p);
    return(0);
}