#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::cout;

double checkChar(char *argv)
{
    double i;

    if (strlen(argv) == 1)
    {
        if (argv[0] >= 32 && argv[0] < 127)
        {
            if (argv[0] >= 48 && argv[0] <= 57)
            {
                i = atof(argv);
                return i;
            }
            double alpha = argv[0];
            return alpha;
        }
        else
            i = atof(argv);
    }
    else
        i = atof(argv);
    return i;
}

int checkLiterals(char *argv)
{
    std::string literals = argv;
    if (literals == "nan" || literals == "nanf")
    {
        cout << "char: impossible\n";
        cout << "int: impossible\n";
        cout << "float: nanf\n";
        cout << "double: nan\n";
        return 1;
    }
    else if (literals == "inf" || literals == "+inf" || literals == "+inff")
    {
        cout << "char: impossible\n";
        cout << "int: inf\n";
        cout << "float: inff\n";
        cout << "double: inf\n";
        return 1;
    }
    else if (literals == "-inf" || literals == "-inff")
    {
        cout << "char: impossible\n";
        cout << "int: -inf\n";
        cout << "float: -inff\n";
        cout << "double: -inf\n";
        return 1;
    }
    return 0;
}

void convert(char *argv)
{
    double i;

    i = checkChar(argv);
    if (checkLiterals(argv) == 1)
        return;
    if (static_cast<int>(i) <= 31 || static_cast<int>(i) >= 127)
        cout << "char: Non displayable\n";
    else
        cout << "char: " << static_cast<char>(i) << "\n";
    if (i > 2147483647 || i < -2147483648)
        cout << "int: impossible\n";
    else
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