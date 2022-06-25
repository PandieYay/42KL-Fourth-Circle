#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

using std::string;

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
		WrongCat(const WrongCat &a);
		WrongCat &operator = (const WrongCat &a);
        ~WrongCat();
        void makeSound(void) const;
};

#endif