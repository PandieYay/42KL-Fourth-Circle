#include <iostream>
#include <string>

using std::string;
using std::cout;

int main(void)
{
	string brain = "HI THIS IS BRAIN";
	string *strPTR = &brain;
	string &strREF = brain;

	cout << &brain << "\n";
	cout << strPTR << "\n";
	cout << &strREF << "\n";
	cout << brain << "\n";
	cout << *strPTR << "\n";
	cout << strREF << std::endl;
}