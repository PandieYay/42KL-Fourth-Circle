#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

#define size 1

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

	// Animal Test;
    return 0;
}