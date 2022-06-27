#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

#define size 5

int main()
{
	Animal *array[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i= 0; i < size; i++)
		delete array[i];

    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;

    // Dog basic;
    // Dog tmp = basic;
    return 0;
}