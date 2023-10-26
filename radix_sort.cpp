#include <iostream>
#include <bits\stdc++.h>
using namespace std;
void CountSort(int arr[], int n, int b[], int r[]) {
    int maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < mini)
            mini = arr[i];
    }
    if (mini < 0) {
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] - mini;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    int c[maxi + 1];
    for (int i = 0; i <= maxi; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[arr[i]]++;
    }
    for (int i = 1; i <= maxi; i++) {
        c[i] = c[i] + c[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (c[arr[i]] != 0) {
            r[c[arr[i]] - 1] = b[i];
            c[arr[i]]--;
        }
    }
    if (mini < 0) {
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] + mini;
        }
    }
}
void RadixSort(int arr[], int n, int r[])
{
    int count=0, maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>maxi)
        maxi=arr[i];
    }
    int rem=maxi;
    while (rem!=0)
    {
        rem=rem/10;
        count++;
    }
    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i]=0;
    }
    
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[j]=(arr[j]%int(pow(10, i+1)))/int(pow(10, i));
        }
        CountSort(c, n, arr, r);
        for (int i = 0; i < n; i++)
        {
            arr[i]=r[i];
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
    int r[n];
    RadixSort(arr, n, r);
    for (int i = 0; i < n; i++)
    {
        cout<<r[i]<<" ";
    }
}