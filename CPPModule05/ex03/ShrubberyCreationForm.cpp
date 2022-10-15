#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : Form(target + "ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : Form("ShrubberyCreationForm", 145, 137)
{
    _target = a._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
    _target = a._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getIfSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() <= this->getGradeToExecute())
    {
        std::ofstream Shrubbery(_target + "_shrubbery");

        Shrubbery << "       _-_                        _-_\n"
                     "    /~~   ~~\\                  /~~   ~~\\\n"
                     " /~~         ~~\\            /~~         ~~\\\n"
                     "{               }          {               }\n"
                     " \\  _-     -_  /            \\  _-     -_  /\n"
                     "   ~  \\\\ //  ~                ~  \\\\ //  ~\n"
                     "_- -   | | _- _            _- -   | | _- _\n"
                     "  _ -  | |   -_              _ -  | |   -_\n"
                     "      // \\\\                      // \\\\";
        Shrubbery.close();
    }
    else
        throw GradeTooLowException();
}