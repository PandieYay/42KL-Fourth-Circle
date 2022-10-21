#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

using std::cout;

Base *generate(void)
{
    int randomNum;

    srand(time(0));
    randomNum = rand() % 3;
    if (randomNum == 0)
        return (new (A));
    else if (randomNum == 1)
        return (new (B));
    else
        return (new (C));
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        cout << "A" << "\n";
    else if (dynamic_cast<B*>(p))
        cout << "B" << "\n";
    else if (dynamic_cast<C*>(p))
        cout << "C" << "\n";
}

void identify(Base &p)
{
    if (dynamic_cast<A*>(&p))
        cout << "A" << "\n";
    else if (dynamic_cast<B*>(&p))
        cout << "B" << "\n";
    else if (dynamic_cast<C*>(&p))
        cout << "C" << "\n";
}

int main(void)
{
    Base *ptr;
    ptr = generate();
    identify(ptr);
    identify(*ptr);    
}
