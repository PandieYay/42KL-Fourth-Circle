#include "Span.hpp"

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
        addNumber(rand()); 
    }
}

unsigned int Span::shortestSpan(void)
{
    if (_totalN <= 1)
        throw notEnoughNums();
    vector<int>temp = _numbers;

    vector<unsigned int> clone(_numbers.begin(), _numbers.end());
    std::sort(clone.begin(), clone.end());
    clone.erase(std::unique(clone.begin(), clone.end()), clone.end());
    //Checks if there were only duplicate numbers
    if (clone.size() == 1)
        return 0;
    unsigned int minDiff = clone[1] - clone[0];
    for (unsigned long i = 1; i < clone.size() - 1; i++)
        if (clone[i + 1] - clone[i] < minDiff)
            minDiff = clone[i + 1] - clone[i];
    clone.clear();
    return minDiff;
}

unsigned int Span::longestSpan(void)
{
    if (_totalN <= 1)
        throw notEnoughNums();
    std::pair<vector<int>::iterator, vector<int>::iterator> ptr;
    ptr = std::minmax_element(_numbers.begin(), _numbers.end());
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