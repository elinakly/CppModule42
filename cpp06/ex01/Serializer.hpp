#pragma once

#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer() = delete;
        Serializer(const Serializer &other) = delete;
        const Serializer& operator=(const Serializer& other) = delete;
        ~Serializer() = delete;
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};