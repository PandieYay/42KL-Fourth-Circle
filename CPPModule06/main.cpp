#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::cout;

void nanCase(void)
{
    cout << "char: impossible\n";
    cout << "int: impossible\n";
    cout << "float: nanf\n";
    cout << "double: nan\n";
}

void convert(char *argv)
{
    double i = atof(argv);
    std::string literals = argv;

    //TODO: HANDLE INF +- cases BROOO
    if (literals == "nan" || literals == "nanf")
    {
        nanCase();
        return;
    }

    if (static_cast<int>(i) < 31 || static_cast<int>(i) >= 127)
        cout << "char: Non displayable\n";
    else
        cout << "char: " << static_cast<char>(i) << "\n";
    cout << "int: " << static_cast<int>(i) << "\n";
    cout << "float: " << static_cast<float>(i);
    if (i == static_cast<int>(i))
        cout << ".0f";
    cout << "\n";
    cout << "double: " << i;
    if (i == static_cast<int>(i))
        cout << ".0";
    cout << "\n";
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (-1);
    convert(argv[1]);
}