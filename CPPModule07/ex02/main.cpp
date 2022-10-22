#include "Array.tpp"

int main(void)
{
    //Test case 1
    {
        Array<int> a(1);

        try
        {
            a[0] = 5;
            cout << a[0] << "\n";
        }
        catch (std::exception &e)
        {
            cout << "Caughttt " << e.what() << "\n";
        }
    }

    //Test case 2
    {
        Array<char> a(5);

        try
        {
            a[4] = 'A';
            cout << a[4] << "\n";
        }
        catch (std::exception &e)
        {
            cout << "Caughttt " << e.what() << "\n";
        }
    }
}

// #include <iostream>
// #include "Array.tpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }