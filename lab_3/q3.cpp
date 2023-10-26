#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int prod(int s, int e, int arr[])
{
    while (s != e)
    {
        int n = (s + e) / 2;
        int ncount = 0, flag = 0;
        for (int i = s; i <= e; i++)
        {
            if (arr[i] < 0)
                ncount++;
            if (arr[i] == 0)
                flag++;
        }
        if (ncount % 2 != 0)
        {
            return max(prod(s, n, arr), prod(n + 1, e, arr));
        }
        else if (ncount % 2 == 0 && flag == 0)
        {
            int p = 1;
            for (int i = s; i <= e; i++)
            {
                p *= arr[i];
            }
            return p;
        }
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
    cout << prod(0, n - 1, arr);
}