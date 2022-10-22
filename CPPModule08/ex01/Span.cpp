#include "Span.hpp"
#include <iostream>

using std::cout;

void Span::addNumber(int num)
{
    if (_totalN >= _maxCap)
        throw tooMuchNums();
    _numbers.push_back(num);
    ++_totalN;
}

void Span::manyNumbers(int range)
{
    srand(time(0));
    for (int i = 0; i < range; i++)
    {
        int num = rand() % 10000;
        cout << "The Num: " << num << "\n";
        addNumber(num); 
    }
}

unsigned int Span::shortestSpan(void)
{
    if (_totalN <= 1)
        throw notEnoughNums();
    vector<int>temp = _numbers;

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    _numbers.erase(std::remove(_numbers.begin(), _numbers.end(), min), _numbers.end());
    int min2 = *std::min_element(_numbers.begin(), _numbers.end());

    _numbers = temp;
    return (min2 - min);
}

unsigned int Span::longestSpan(void)
{
    if (_totalN <= 1)
        throw notEnoughNums();
    std::pair<vector<int>::iterator, vector<int>::iterator> ptr;
    ptr = std::minmax_element(_numbers.begin(), _numbers.end());
    // cout << *ptr.first;
    return (*ptr.second - *ptr.first);
}

Span::Span(unsigned int N)
{
    _totalN = 0;
    _maxCap = N;
}

Span::Span(const Span &a)
{
    _numbers = a._numbers;
    _totalN = a._totalN;
    _maxCap = a._maxCap;
}

Span &Span::operator=(const Span &a)
{
    _numbers = a._numbers;
    _totalN = a._totalN;
    _maxCap = a._maxCap;
    return *this;
}

Span::~Span()
{
}

const char *Span::tooMuchNums::what() const throw()
{
    return ("Too much numbers\n");
}

const char *Span::notEnoughNums::what() const throw()
{
    return ("Not enough numbers\n");
}