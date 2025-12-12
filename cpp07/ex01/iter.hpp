#pragma once

#include <iostream>
#include <string>

template <typename T, typename Func>
void iter(T* adress, const size_t length, Func f) // support const and non const
{
    for(size_t i = 0; i < length; i++)
    {
        f(adress[i]);
    }
}