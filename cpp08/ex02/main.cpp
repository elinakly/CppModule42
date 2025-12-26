#include "MutantStack.hpp"

int main()
{
    std::cout << "========Test const iter in int=======\n";
    MutantStack<int> stack; // stack doesnt support init //so no {1, 2, 3, 4}
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    for(MutantStack<int>::const_iterator const_it = stack.begin(); const_it != stack.end(); ++const_it)
        std::cout << *const_it << "\n";
    std::cout << "========Test const iter in int=======\n";
    std::cout << "==========Test iter =========\n";    
    MutantStack<int> stack1; 
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    for(MutantStack<int>::iterator it = stack1.begin(); it != stack1.end(); ++it)
        std::cout << (*it + 1) << "\n";
    std::cout << "==========Test iter=========\n";
        std::cout << "==========Test iter with float=========\n";    
    MutantStack<float> stack2; 
    stack2.push(1.2);
    stack2.push(2.2);
    stack2.push(3.4);
    stack2.push(4.3);
    stack2.push(5.5);
    for(MutantStack<float>::iterator it2 = stack2.begin(); it2 != stack2.end(); ++it2)
        std::cout << (*it2 + 1) << "\n";
    std::cout << "==========Test iter with float=========\n";   
}