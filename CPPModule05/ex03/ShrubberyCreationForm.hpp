#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

using std::string;

class ShrubberyCreationForm : public Form
{
private:
    string _target;

public:
    ShrubberyCreationForm(string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &a);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};

#endif