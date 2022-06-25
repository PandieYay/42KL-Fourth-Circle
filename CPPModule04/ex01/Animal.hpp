#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Animal {
    protected:
        string _type;
    public:
        Animal();
		Animal(const Animal &a);
		Animal &operator = (const Animal &a);
        virtual ~Animal();
        string getType(void) const;
        virtual void makeSound(void) const;
};

#endif