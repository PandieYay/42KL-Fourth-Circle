#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

using std::string;

class Bureaucrat
{
private:
    string _name;
    int _grade;

public:
    Bureaucrat(string name, int grade);
    Bureaucrat(const Bureaucrat &a);
    Bureaucrat &operator=(const Bureaucrat &a);
    ~Bureaucrat();
    string getName(void);
    int getGrade(void);
    void incrementGrade(int n);
    void decrementGrade(int n);
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
};

#endif