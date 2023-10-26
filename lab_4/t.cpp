#include <iostream>
using namespace std;

pair<int, int> solve(int *arr, int low, int high, int n)
{
    if (low == high)
    {
        return {arr[low], 1};
    }
    if (high - low == 1)
    {
        if (arr[low] == arr[high])
        {
            return {arr[low], 2};
        }
        else
        {
            return {arr[low], 1};
        }
    }
    int mid = (low + high) / 2;
    pair<int, int> left = solve(arr, low, mid, n);
    pair<int, int> right = solve(arr, mid + 1, high, n);

    int count1 = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        if (arr[i] == left.first)
            count1++;
    }
    int count2 = 0;
    for (int i = 0; i <= mid; i++)
    {
        if (arr[i] == right.first)
            count2++;
    }

    if (right.first == left.first)
    {
        return {left.first, count1 + count2};
    }
    if (left.second + count1 > right.second + count2)
    {
        return {left.first, left.second + count1};
    }
    else
    {
        return {right.first, right.second + count2};
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> ans = solve(arr, 0, n - 1, n);
    cout << ans.first << " " << ans.second;
}