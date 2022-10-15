#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

using std::cout;

int main(void)
{
    // Test case 1
    {
        Bureaucrat bob("bob", 5);
        Intern someRandomIntern;
        Form *rrf;
        rrf = someRandomIntern.makeForm("robotomy requesta", "Bender");
        if (rrf)
        {
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
        }
    }
}