#pragma once 

#include <iostream>

template <typename T>
void ft_swap(T &nbr1, T &nbr2)
{
    T tmp  = nbr1;
    nbr1 = nbr2;
    nbr2 = tmp;
}

template <typename T>
T ft_min(const T& nbr1,const T& nbr2)
{
    return(nbr1 < nbr2 ? nbr1 : nbr2);
}

template <typename T>
T ft_max (const T& nbr1,const T& nbr2)
{
    return(nbr1 > nbr2 ? nbr1 : nbr2);
}