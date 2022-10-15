#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

using std::string;

class Bureaucrat;

class Form
{
private:
    string _name;
    bool _isSigned;
    int _gradeToSign;
    int _gradeToExecute;

public:
    Form(string name, int gradeToSign, int gradeToExecute);
    Form(const Form &a);
    Form &operator=(const Form &a);
    ~Form();
    string getName(void) const;
    bool getIfSigned(void) const;
    int getGradeToSign(void);
    int getGradeToExecute(void) const;
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    void beSigned(Bureaucrat bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#endif