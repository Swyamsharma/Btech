#include <iostream>
#include <vector>
using namespace std;
void merge(int lo, int mid, int hi, int A[])
{
    int i = lo, j = mid + 1, k = lo;
    int B[hi + 1];
    while (i <= mid && j <= hi)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= hi)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = lo; i <= hi; i++)
    {
        A[i] = B[i];
    }
}
void MS(int A[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (hi + lo) / 2;
        MS(A, lo, mid);
        MS(A, mid + 1, hi);
        merge(lo, mid, hi, A);
    }
}
int median(int arr[], int e, int *a, int s, int r)
{
    for (int i = 0; i < r; i++)
    {
        if ((e + i) == s - 1)
        {
            MS(arr, e, e + i);
            *a = arr[(e + e + i) / 2];
            return e + i + 1;
        }
    }
    MS(arr, e, e + r - 1);
    *a = arr[(e + e + r - 1) / 2];
    return e + r;
    /*if ((e+1)==s-1)
    {
        MS(arr, e, e+1);
        *a=arr[(e+e+1)/2];
        return e+2;
    }
    else  if ((e)==s-1)
    {
        *a=arr[e];
        return e;
    }
    else{
    MS(arr, e, e+2);
    *a=arr[(e+e+2)/2];
    return e+3;
    } */
}
int mediansofmedian(int arr[], int s, int r)
{
    int size;
    if (s%r!=0)
    size=s / r + 1;
    else
    size=s/r;
    int medians[size];
    int e = 0;
    int median1 = arr[0];
    for (int i = 0; i < size; i++)
    {
        e = median(arr, e, &medians[i], s, r);
        median1 = medians[i];
    }
    if (s != 1)
    {
        median1 = mediansofmedian(medians, s / r + 1, r);
    }
    return median1;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int midean1;
    int arr[n];
    int r = 5;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    midean1 = mediansofmedian(arr, n, r);
    cout << endl;
    cout << midean1;
}