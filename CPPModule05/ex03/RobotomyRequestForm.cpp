#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string target) : Form(target + "RobotomyRequestForm", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : Form("RobotomyRequestForm", 72, 45)
{
    _target = a._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
    _target = a._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIfSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        srand(time(0));
        cout << "ZzzzZZzzzZZZZZZZZZ\n";
        if (rand() % 2 == 0)
            cout << _target << " has been robotomized successfully\n";
        else
            cout << "Operation failed, " << _target << " is dead X_X\n";
    }
    else
        throw GradeTooLowException();
}