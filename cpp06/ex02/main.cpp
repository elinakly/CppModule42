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

void identify(Base* p) //if we cast to pointer cast throws an "nullptr"
{
    if (dynamic_cast<A*>(p))
        std::cout << "identity by pinter A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "identity by pinter B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "identity by pinter C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) //if we cast to reff cast throws an exception "bad cast"
{
    {
        try
        { 
            A& a = dynamic_cast<A&>(p);
            (void)a;
            std::cout << "identity by ref A\n";
            return;
        } 
        catch (std::bad_cast& e) 
        {
        }
    }

    {    
        try
        { 
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "identity by ref B\n";
            return;
        } 
        catch (std::bad_cast& e) 
        {
        }
    }
    {
        try
        { 
            C& c = dynamic_cast<C&>(p);
            (void)c;
            std::cout << "identity by ref C\n";
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