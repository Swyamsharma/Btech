#include <iostream>
using namespace std;
int TernarySearch(int arr[], int s, int e, int k)
{
    int mid1 = 0, mid2 = 0, index = 0;
    while (s <= e)
    {
        mid1 = s + (e - s) / 3;
        mid2 = s + (e - s) * 2 / 3;
        if (arr[mid1] == k)
        {
            return mid1;
        }
        if (arr[mid2] == k)
        {
            return mid2;
        }

        else if (arr[mid2] < k)
            s = mid2 + 1;
        else if (arr[mid1] > k)
            e = mid1 - 1;
        else
        {
            s = mid1 + 1;
            e = mid2 - 1;
        }
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
    cout << "Using Ternary search the element exists at index " << TernarySearch(arr, 0, n, key) << endl;
}