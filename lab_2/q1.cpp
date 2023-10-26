#include <iostream>
using namespace std;
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
    int max = 0, min = 0;
    if (arr[0] > arr[n - 1])
    {
        // descending
        max = arr[0];
        min = arr[n - 1];
    }
    else if (arr[0] < arr[n - 1])
    {
        // ascending
        max = arr[n - 1];
        min = arr[0];
    }
    cout << "The maximum element is " << max << " and the minimum element is " << min << endl;
    return 0;
}