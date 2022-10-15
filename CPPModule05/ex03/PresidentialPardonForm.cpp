#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) : Form(target + "PresidentialPardonForm", 25, 5)
{
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : Form("PresidentialPardonForm", 25, 5)
{
    _target = a._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
    _target = a._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIfSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
    }
    else
        throw GradeTooLowException();
}