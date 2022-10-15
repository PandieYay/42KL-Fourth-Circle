#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::string;

class Form;

class Intern
{
public:
    Intern();
    Intern(const Intern &a);
    Intern &operator=(const Intern &a);
    ~Intern();
    Form *makeForm(string form, string target);
};

#endif