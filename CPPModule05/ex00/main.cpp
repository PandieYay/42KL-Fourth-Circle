#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;

int main(void)
{
    // Test case 1
    cout << "Test Case 1\n";
    try
    {
        Bureaucrat bob("bob", 1);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
        bob.decrementGrade(149);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        cout << "Exception caught: " << e.what() << "See it worked\n";
    }
    cout << "\nTest Case 2\n";
    // Test case 2
    try
    {
        Bureaucrat bob("bob", 1);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
        bob.incrementGrade(1);
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        cout << "Exception caught: " << e.what() << "See it worked\n";
    }
    cout << "\nTest Case 3\n";
    // Test case 3
    try
    {
        Bureaucrat bob("bob", 150);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
        bob.decrementGrade(1);
    }
    catch (std::exception &e)
    {
        cout << "Exception caught: " << e.what() << "Nice\n";
    }
}