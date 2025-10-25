#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    std::cout << "\n===================\n";
    std::cout << "\n     WRONG TEST    \n";
    std::cout << "\n===================\n";

    const WrongAnimal* WrongMeta = new WrongAnimal();
    const Animal* J = new Dog();
    const WrongAnimal* I = new WrongCat();
    std::cout << J->getType() << " " << std::endl;
    std::cout << I->getType() << " " << std::endl;
    I->makeSound(); //will output the cat sound!
    J->makeSound();
    WrongMeta->makeSound();
    delete WrongMeta;
    delete J;
    delete I;

    return 0;
}