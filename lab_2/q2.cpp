#include <iostream>
using namespace std;
int BinarySearch(int arr[], int s, int e, int k)
{
    int mid = 0, index = 0;
    while (s <= e)
    {
        mid = s - (s - e) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return -1;
}
int AlphaSearch(int arr[], int s, int e, int k)
{
    int mid = 0, index = 0;
    while (s <= e)
    {
        mid = s + (e - s) * 2 / 3;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return -1;
}
int BetaSearch(int arr[], int s, int e, int k)
{
    int mid = 0, index = 0;
    while (s <= e)
    {
        mid = s - (s - e) / 4;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Using Binary search the element exists at index " << BinarySearch(arr, 0, n, key) << endl;
    cout << "Using Alpha search the element exists at index " << AlphaSearch(arr, 0, n, key) << endl;
    cout << "Using Beta search the element exists at index " << BetaSearch(arr, 0, n, key) << endl;
}