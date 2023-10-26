#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ". ";
        }
        cout << endl;
    }
    int arg;
    cout << "Enter the arg: ";
    cin >> arg;
    int arg1 = 0, dir = 0;
    for (int i = 0; i < n; i++)
    {
        if (arg1 > arg)
            arg1 = 0;

        if (arg1 > 0)
        {
            if (dir % 2 != 0)
            {
                for (int k = 0; k < n - 1; k++)
                {
                    cout << "  ";
                }
                cout << ". ";
                cout << endl;
                arg1++;
            }
            else if (dir % 2 == 0)
            {
                cout << ". ";
                for (int k = 0; k < n - 1; k++)
                {
                    cout << "  ";
                }
                cout << endl;
                arg1++;
            }
        }
        else if (arg1 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ". ";
            }

            arg1++;
            dir++;
            cout << endl;
        }
    }
}