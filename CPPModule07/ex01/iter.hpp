#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter (T *x, int y, void (*print)(T const &random))
{
    for (int i = 0; i < y; i++)
        print(x[i]);
}

#endif