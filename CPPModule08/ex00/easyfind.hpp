#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>

template <typename T> int easyfind(T container, int n)
{
    typename T::iterator i = std::find(container.begin(), container.end(), n);
    if (i == container.end())
        return -1;
    return i - container.begin();
}

#endif