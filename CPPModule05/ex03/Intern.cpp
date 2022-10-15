#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &a)
{
    (void)a;
}

Intern &Intern::operator=(const Intern &a)
{
    (void)a;
    return *this;
}

Intern::~Intern()
{
}

Form		*makePresidentialPardonForm(string const target)
{
	Form	*form = new PresidentialPardonForm(target);

	return (form);
}

Form		*makeRobotomyRequestForm(string const target)
{
	Form	*form = new RobotomyRequestForm(target);

	return (form);
}

Form		*makeShrubberyCreationForm(string const target)
{
	Form	*form = new ShrubberyCreationForm(target);

	return (form);
}

Form *Intern::makeForm(string form, string target)
{
    string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form*  (*array[3])(string) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (formList[i] == form)
            return (array[i](target));
    }
    cout << "Form name doesn't exist, there's: shrubbery creation, robotomy request, and presidential pardon.\n";
    return (NULL);
}
