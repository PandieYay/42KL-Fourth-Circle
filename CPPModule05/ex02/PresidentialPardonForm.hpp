#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class PresidentialPardonForm : public Form
{
private:
    string _target;

public:
    PresidentialPardonForm(string target);
    PresidentialPardonForm(const PresidentialPardonForm &a);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};

#endif