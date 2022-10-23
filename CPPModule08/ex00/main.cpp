#include "easyfind.hpp"
#include <array>
#include <iostream>

using std::cout;

int main(void)
{
    std::array<int, 6> ar = {1, 2, 3, 4, 5, 6};
    cout << "Index of right side in left array is: " << easyfind(ar, 6) << "\n";

    std::array<char, 3> ar2 = {'A', 'B', 'C'};
    cout << "Index of right side in left array is: " << easyfind(ar2, 2) << "\n";

    //Wrong index
    cout << "Index of right side in left array is: " << easyfind(ar2, 'C') << "\n";
}