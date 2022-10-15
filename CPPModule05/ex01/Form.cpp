#include "Form.hpp"

#include <iostream>

string Form::getName(void)
{
    return _name;
}

bool Form::getIfSigned(void)
{
    return _isSigned;
}

int Form::getGradeToSign(void)
{
    return _gradeToSign;
}

int Form::getGradeToExecute(void)
{
    return _gradeToExecute;
}


Form::Form(string name, int gradeToSign, int gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    _name = name;
    _isSigned = false;
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExecute;
}

Form::Form(const Form &a){
    _name = a._name;
    _isSigned = a._isSigned;
    _gradeToSign = a._gradeToSign;
    _gradeToExecute = a._gradeToExecute;
}

Form &Form::operator=(const Form &a){
    _name = a._name;
    _isSigned = a._isSigned;
    _gradeToSign = a._gradeToSign;
    _gradeToExecute = a._gradeToExecute;
	return *this;
}

Form::~Form()
{
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    //Means if bureaucrat grade is higher than grade to sign
    if (bureaucrat.getGrade()  <= _gradeToSign)
    {
        _isSigned = true;
    }
    else
        throw GradeTooLowException();
}