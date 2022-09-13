#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;

int main(void)
{
    // Test case 1
    try
    {
        Bureaucrat bob("bob", 1);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
        bob.decrementGrade(149);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
    }
    catch (std::exception &e)
    {
        cout << e.what();
    }
    // Test case 2
    try
    {
        Bureaucrat bob("bob", 1);
        cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
        bob.incrementGrade(1);
    }
    catch (std::exception &e)
    {
        cout << e.what();
    }
}