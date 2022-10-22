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
unsigned int Array<T>::size(void) const
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
    _size = a._size;
    _array = new T[a.size()];
    for (unsigned int i = 0; i < a.size(); i++)
        _array[i] = a._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
    if (_size != 0)
        delete []_array;
    _size = a._size;
    _array = new T[a.size()];
    for (unsigned int i = 0; i < a.size(); i++)
        _array[i] = a._array[i];
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