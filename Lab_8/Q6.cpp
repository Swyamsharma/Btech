#include <iostream>
using namespace std;
int search(int arr[], int hi, int lo)
{
    int mid=(hi+lo)/2;
    if (arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
    {
        return arr[mid];
    }
    else if (arr[lo]>arr[mid+1])
    {
        return search(arr, mid-1, lo);
    }
    else
    {
        return search(arr, mid+1, hi);
    }
    
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int midean1;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<search(arr, n-1, 0)<<endl;
}