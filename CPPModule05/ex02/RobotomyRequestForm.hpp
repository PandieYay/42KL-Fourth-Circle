#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <cstdlib>
#include <time.h>

using std::string;

class RobotomyRequestForm : public Form
{
private:
    string _target;

public:
    RobotomyRequestForm(string target);
    RobotomyRequestForm(const RobotomyRequestForm &a);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
};

#endif