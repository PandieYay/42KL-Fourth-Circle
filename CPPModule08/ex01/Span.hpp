#ifndef SPAN_HPP
#define SPAN_HPP

#include <array>
#include <algorithm>
#include <vector>
#include <utility>

using std::vector;

class Span {
    private:
        vector<int> _numbers;
        unsigned int _totalN;
        unsigned int _maxCap;
    public:
        Span(unsigned int N);
		Span(const Span &a);
		Span &operator = (const Span &a);
        ~Span();
        void addNumber(int num);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);
        class tooMuchNums : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class notEnoughNums : public std::exception
        {
            public:
                const char *what() const throw();
        };
        void manyNumbers(int range);
};

#endif