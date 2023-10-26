#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    long long int n1 = 0, n2 = 1, n3 = 1;
    if (n == 1)
    {
        cout << "1";
    }

    for (int i = 0; i < n - 1; ++i)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }

    cout << n3;
}