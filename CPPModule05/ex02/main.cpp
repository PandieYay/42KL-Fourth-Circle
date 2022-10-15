#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

using std::cout;

int main(void)
{
    // Test case 1: Shrubbery sign 145, exec 137
    {
        cout << "Test Case 1\n";
        Bureaucrat bob("bob", 145);
        ShrubberyCreationForm form("bob");
        bob.signForm(form);
        bob.executeForm(form);
    }
    // Test case 2: sign 72, exec 45
    {
        cout << "\nTest Case 2\n";
        Bureaucrat bob("bob", 45);
        RobotomyRequestForm form("Robert");
        bob.signForm(form);
        bob.executeForm(form);
    }

    // Test case 3: sign 25, exec 5
    {
        cout << "\nTest Case 3\n";
        Bureaucrat bob("bob", 5);
        PresidentialPardonForm form("ObamaGaming");
        bob.signForm(form);
        bob.executeForm(form);
    }
}