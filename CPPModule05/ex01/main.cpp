#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

using std::cout;

int main(void)
{
    // Test case 1
    cout << "Test Case 1\n";
    Bureaucrat bob("bob", 1);
    cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
    bob.decrementGrade(149);
    cout << bob.getName() << ", bureaucrat grade " << bob.getGrade() << "." << std::endl;
    Form form("Treaty of Peace", 149, 150);
    bob.signForm(form);
    
    // Test case 2
    cout << "\nTest Case 2\n";
    bob.incrementGrade(1);
    bob.signForm(form);
    cout << form.getIfSigned() << std::endl;
}