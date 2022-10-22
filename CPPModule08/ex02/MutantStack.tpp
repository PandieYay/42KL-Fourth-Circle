#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &a)
{
	*this = a;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &a)
{
	(void)a;
	return *this;
}


template <typename T>
MutantStack<T>::~MutantStack()
{
}