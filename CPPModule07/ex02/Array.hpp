#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>

template <typename T> class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
		Array(const Array &a);
		Array &operator = (const Array &a);
        ~Array();
        T &operator [] (unsigned int index);
        unsigned int size(void) const;
        class IndexOutOfBounds : public std::exception
        {
        public:
            const char *what() const throw();
        };
};

#endif