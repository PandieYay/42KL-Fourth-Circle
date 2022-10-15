#include "Bureaucrat.hpp"

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
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(int n)
{
    _grade += n;
    if (_grade > 150)
        throw GradeTooLowException();
    else if (_grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(string name, int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    _name = name;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a){
    _name = a._name;
    _grade = a._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a){
    _name = a._name;
    _grade = a._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low\n");
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
       form.beSigned(*this);
       cout << _name << " successfully signed " << form.getName() << "!\n";
    }
    catch(Form::GradeTooLowException &e)
    {
        cout << _name << " couldn't sign " << form.getName() << " because " <<  e.what() << '\n';
    }
}