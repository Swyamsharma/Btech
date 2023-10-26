#include <iostream>
using namespace std;
int Max(int s, int e, int arr[])
{
    while (s != e)
    {
        int n = (s + e) / 2;
        return max(Max(s, n, arr), Max(n + 1, e, arr));
    }
    return arr[s];
}
int Min(int s, int e, int arr[])
{
    while (s != e)
    {
        int n = (s + e) / 2;
        return min(Min(s, n, arr), Min(n + 1, e, arr));
    }
    return arr[s];
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
    cout << "Max: " << Max(0, n - 1, arr) << endl;
    cout << "Min:" << Min(0, n - 1, arr) << endl;
}