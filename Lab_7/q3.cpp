#include <iostream>
#include <bits\stdc++.h>
using namespace std;
int mul(int *a1, int *a2, int n)
{
    
}
int main()
{
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int n=pow(4, k);
    int a1[n][n], a2[n][n];
    cout<<"Enter the first matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a1[i][j];
        }
        
    }
    cout<<"Enter the second matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a2[i][j];
        }
        
    }

}