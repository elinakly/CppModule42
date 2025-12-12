#include "whatever.hpp"

int main()
{
    // ft_swap(3, 3.0f);
    // ft_swap(3, 2);
    // std::cout << ft_min(4.0f, 3.0f) << "\n";
    // std::cout << ft_max(4, 4) << "\n";
    int a = 2;
    int b = 3;
    ft_swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ft_min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ft_max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ft_swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ft_min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ft_max( c, d ) << std::endl;
    return 0;
    return(0);
}