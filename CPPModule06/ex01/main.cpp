#include "Data.hpp"
#include <iostream>
using std::cout;

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
    Data data;
    uintptr_t random = 0;
    Data *deseralizedPtr = NULL;

    cout << "data address: " << &data << "\n";
    random = serialize(&data);
    cout << "Number from address: " << random << "\n";
    deseralizedPtr = deserialize(random);
    cout << "deseralizedPtr: " << deseralizedPtr << "\n";
}