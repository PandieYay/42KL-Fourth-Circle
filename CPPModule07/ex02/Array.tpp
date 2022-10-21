#include "Array.hpp"
#include <iostream>

using std::cout;

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw IndexOutOfBounds();
    }
    return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void)
{
    return _size;
}

template <typename T>
Array<T>::Array()
{
    _array = new T[0];
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _array = new T[n];
    _size = n;
}

template <typename T>
Array<T>::Array(const Array &a)
{
    _array = a._array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
    _array = a._array;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw()
{
    return ("Index out of bounds\n");
}