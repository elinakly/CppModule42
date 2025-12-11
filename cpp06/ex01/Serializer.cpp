#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr)); // reintepret cast doesnt change the data, only how the bytes are intepreted, the memory stays same
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}