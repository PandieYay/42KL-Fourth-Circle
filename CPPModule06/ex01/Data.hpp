#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Data {
    private:
        int _key;
    public:
        Data();
		Data(const Data &a);
		Data &operator = (const Data &a);
        ~Data();
};

#endif