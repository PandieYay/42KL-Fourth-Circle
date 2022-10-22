#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <string>

using std::stack;

template <typename T> class MutantStack : public stack<T>
{
    public:
        MutantStack();
        MutantStack(unsigned int n);
		MutantStack(const MutantStack &a);
		MutantStack &operator = (const MutantStack &a);
        ~MutantStack();


		typedef typename stack<T>::container_type::iterator    iterator;
		iterator begin(void) {	return std::begin(this->c); };
		iterator end(void) {	return std::end(this->c); };
};

#endif