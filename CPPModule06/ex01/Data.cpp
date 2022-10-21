#include "Data.hpp"

Data::Data(){
    _key = 5;
}

Data::Data(const Data &a){
    _key = a._key;
}

Data &Data::operator=(const Data &a){
    _key = a._key;
    return *this;
}

Data::~Data(){
}