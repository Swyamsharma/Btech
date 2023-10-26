#include <iostream>
using namespace std;
int Find(int s, int e, int arr[])
{
    while (s != e)
    {
        int n = (s + e) / 2;
        if (arr[n] == n + 1)
        {
            return Find(n + 1, e, arr);
        }
        else
            return Find(s, n, arr);
    }
    return arr[s] - 1;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Find(0, n - 1, arr) << endl;
}