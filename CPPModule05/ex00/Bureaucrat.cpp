#include "Bureaucrat.hpp"

#include <iostream>
using std::cout; // remove later

void Bureaucrat::_GradeTooHighException(void)
{
    throw std::range_error("Grade too high bro");
}

void Bureaucrat::_GradeTooLowException(void)
{
    throw std::range_error("Grade too low bro");
}

string Bureaucrat::getName(void)
{
    return _name;
}

int Bureaucrat::getGrade(void)
{
    return _grade;
}

void Bureaucrat::incrementGrade(int n)
{
    _grade -= n;
    if (_grade > 150)
        _GradeTooLowException();
    else if (_grade < 1)
        _GradeTooHighException();
}

void Bureaucrat::decrementGrade(int n)
{
    _grade += n;
    if (_grade > 150)
        _GradeTooLowException();
    else if (_grade < 1)
        _GradeTooHighException();
}

Bureaucrat::Bureaucrat(string name, int grade)
{
    if (grade > 150)
        _GradeTooLowException();
    else if (grade < 1)
        _GradeTooHighException();
    _name = name;
    _grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}
