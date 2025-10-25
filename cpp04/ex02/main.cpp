#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // const Animal* meta = new Animal(); //wont work bc it abstract virtual
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    // meta->makeSound(); //wont work
    // delete meta;
    delete j;
    delete i;


    const Animal* a = new Dog();
    const Animal* b = new Cat();
    delete a;//should not create a leak
    delete b;
    std::cout << "\n===================\n";
    std::cout << "\n     BRAIN TEST    \n";
    std::cout << "\n===================\n";
    int size = 4;
    Animal *Animals[size];
    for (int i = 0; i < size/2; i++)
        Animals[i] = new Dog();
    for (int i = size/2; i < size; i++)
        Animals[i] = new Cat();
    for(int i = 0; i < size; i++)
        delete(Animals[i]);
    return 0;
}