#include "RPN.hpp"
static std::stack<int> st;

bool calculate(const char& op)
{
    if (st.size() < 2)
        return(std::cerr << "Error: invalid RPN expression\n", false);
    int b = st.top(); //get element from top
    st.pop(); // remove from stack
    int a = st.top();
    st.pop();
    int result;
    switch(op)
    {
        case '+':
            result = a + b; 
            break;
        case '-': 
            result = a - b; 
            break;
        case '*':
            result = a * b;
            break;
        case '/': 
            if (b == 0) 
                return (std::cerr << "Error: divide by zero\n", false);
            result = a / b;
            break;
    }
    st.push(result); //push result to stack
    return(true);
}

bool valid_input(char *argv)
{
    std::string expr(argv); //cope from char * to std::string
    std::istringstream iss(expr); // convert string to istringstream
    std::string token; // string of tokens
    while (iss >> token) //extracts one token
    {
        if (token.length() != 1)
            return(std::cerr << "Error: wrong input : " << token << "\n", false);
        else if(std::isdigit(token[0]))   
            st.push(token[0] - '0');
        else if (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*')
        {
            if(!calculate(token[0]))
            {
                while (!st.empty())
                    st.pop();
                return(false);
            }
        }
        else
            return(std::cerr << "Error: wrong input " << token << "\n", false);
    }
    if (st.size() != 1)
        return(std::cerr << "Error: invalid RPN expression\n", false);
    else 
    {
        std::cout << "Result is : " << st.top() << "\n";
        st.pop(); //to clean a stack
    }
    return(true);
}
