#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<int, int> Max(int s, int e, int arr[])
{
    if (s == e)
    {
        return {arr[s], INT_MIN};
    }
    int n = (s + e) / 2;
    pair<int, int> left = Max(s, n, arr);
    pair<int, int> right = Max(n + 1, e, arr);
    int maxi, smaxi;
    maxi = left.first > right.first ? left.first : right.first;
    if (left.first == right.first)
    {
        smaxi = max(left.second, right.second);
    }
    else
        smaxi = max(min(left.first, right.first), max(left.second, right.second));
    return {maxi, smaxi};
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
    cout << "Max: " << Max(0, n - 1, arr).first << endl;
    cout << "Second Max: " << Max(0, n - 1, arr).second << endl;
}