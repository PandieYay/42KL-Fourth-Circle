#include "Span.hpp"
#include <iostream>
#include <limits.h>

using std::cout;

int main(void)
{
    // Test case pdf
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Min Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Max Span: " << sp.longestSpan() << std::endl;
    }

    // Test Case 2
    {
        Span sp = Span(3);
        sp.addNumber(-2);
        sp.addNumber(-1);
        sp.addNumber(INT_MAX);
        std::cout << "Min Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Max Span: " << sp.longestSpan() << std::endl;
    }

    //Test case 3
    {
        Span sp = Span(10000);
        sp.manyNumbers(10000);
        std::cout << "Min Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Max Span: " << sp.longestSpan() << std::endl;
    }
    return 0;
}