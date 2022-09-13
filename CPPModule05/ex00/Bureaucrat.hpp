#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

using std::string;

class Bureaucrat {
    private:
        string _name;
        int _grade;
        void _GradeTooHighException(void);
        void _GradeTooLowException(void);
    public:
        Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		Bureaucrat &operator = (const Bureaucrat &a);
        ~Bureaucrat();
        string getName(void);
        int getGrade(void);
        void incrementGrade(int n);
        void decrementGrade(int n);
};

#endif