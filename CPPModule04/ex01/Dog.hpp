#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

using std::string;

class Dog: public Animal {
    public:
        Dog();
		Dog(const Dog &a);
		Dog &operator = (const Dog &a);
        ~Dog();
        void makeSound(void) const;
};

#endif