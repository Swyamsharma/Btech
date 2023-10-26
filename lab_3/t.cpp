#include <iostream>
#include <limits.h>
using namespace std;

int crossing(int *arr, int low, int mid, int high)
{
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int curr = 1;
    for (int i = mid; i >= 0; i--)
    {
        curr = curr * arr[i];
        if (curr > max1)
            max1 = curr;
        if (curr < min1)
            min1 = curr;
    }
    int max2 = INT_MIN;
    int min2 = INT_MAX;
    curr = 1;
    for (int i = mid + 1; i <= high; i++)
    {
        curr = curr * arr[i];
        if (curr > max2)
            max2 = curr;
        if (curr < min2)
            min2 = curr;
    }

    return max(min1 * min2, max1 * max2);
}
int solve(int *arr, int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int left = solve(arr, low, mid);
    int right = solve(arr, mid + 1, high);
    int ans = crossing(arr, low, mid, high);

    return max(max(left, right), ans);
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

    int ans = solve(arr, 0, n - 1);
    cout << ans;
}