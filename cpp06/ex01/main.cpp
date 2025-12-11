#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data d;
    d.letter = 'a';
    d.number = 42;

    std::cout << "Original pointer: " << &d << "\n";

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized (uintptr_t): " << raw << "\n";

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Restored pointer: " << restored << "\n";

    std::cout << "Restored->letter = " << restored->letter << "\n";
    std::cout << "Restored->number = " << restored->number << "\n";
}