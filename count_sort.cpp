#include <iostream>
#include <bits\stdc++.h>
using namespace std;
void CountSort(int arr[], int n, int b[])
{
    int maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
            mini = arr[i];
    }
    if (mini < 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] - mini;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    int c[maxi + 1];
    for (int i = 0; i <= maxi; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    for (int i = 0; i <= maxi; i++)
    {
        cout << c[i] << " ";
    }
    for (int i = 1; i <= maxi; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    cout << endl;
    for (int i = 0; i <= maxi; i++)
    {
        cout << c[i] << " ";
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (c[arr[i]] != 0)
        {
            b[c[arr[i]] - 1] = arr[i];
            c[arr[i]]--;
        }
    }
    cout << endl;
    if (mini < 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] + mini;
        }
    }
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
    int arr1[n];
    CountSort(arr, n, arr1);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
}
