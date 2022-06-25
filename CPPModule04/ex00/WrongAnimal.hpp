#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

class WrongAnimal {
    protected:
        string _type;
    public:
        WrongAnimal();
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal &operator = (const WrongAnimal &a);
        virtual ~WrongAnimal();
        string getType(void) const;
        void makeSound(void) const;
};

#endif