#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Brain {
    private:
        string ideas[100];
    public:
        Brain();
		Brain(const Brain &a);
		Brain &operator = (const Brain &a);
        ~Brain();
};

#endif