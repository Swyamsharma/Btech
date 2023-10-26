#include <iostream>
using namespace std;
int find_peak(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    if (s == e)
    {
        return arr[s];
    }
    else if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
    {
        return arr[mid];
    }
    else if (arr[mid] < arr[mid + 1])
    {
        return find_peak(arr, mid+1, e);
    }
    else
        return find_peak(arr, s, mid);
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find_peak(arr, 0, n - 1);
}
