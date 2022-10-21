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