#include "Span.hpp"

int main()
{
    std::srand(std::time(nullptr));
    Span sp = Span(10000);
    try{
		for (int i = 0; i < 10000; ++i)
			sp.addNumber(std::rand());
        std::cout << "==============TEST 1================\n" ;   
        std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
        sp.printContaner();
        std::cout << "==============TEST 1================\n" ; 
    }catch(const std::exception &e){
        std::cout << e.what();
        return(1);
    }

    Span span = Span(5);
    try{
        std::list<int> a = {6, 3, 17, 9, 11};
        span.addNumbers(std::begin(a), std::end(a));
        std::cout << "==============TEST 2================\n" ; 
        std::cout << "Shortest Span : " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << span.longestSpan() << std::endl;
        span.printContaner();
        std::cout << "==============TEST 2================\n" ; 
    }catch(const std::exception &e){
        std::cout << e.what();
        return(1);
    }

    Span spanExcept = Span(2); //should throw bc 2 but i put 5 nbrs
    try{
        std::cout << "==============TEST 3================\n" ;
        std::list<int> a = {6, 3, 17, 9, 11};
        spanExcept.addNumbers(std::begin(a), std::end(a));
        std::cout << "Shortest Span : " << spanExcept.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << spanExcept.longestSpan() << std::endl;
        spanExcept.printContaner();
    }catch(const std::exception &e){
        std::cout << e.what();
        std::cout << "==============TEST 3================\n" ;
        return(1);
    }
    return(0);
}