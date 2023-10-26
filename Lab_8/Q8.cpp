#include <iostream>
#include <bits\stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cout<<"Enter the size of the matrix (m, n): ";
    cin>>m;
    cin>>n;
    int t[m+1][n+1];
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if ((i==m-1)&&j!=n||(j==n-1)&&i!=m)
            {
                t[i][j]=1;
            }
            else 
            t[i][j]=0;
        }
        
    }
    
    int maxi=0;
    int max1=0, max2=0;
    for (int i = m-2 ; i >= 0; i--)
    {
        cout<<endl;
        for (int j = n-2; j >= 0; j--)
        {
            if (arr[i][j]>arr[i+1][j])
            {
                max1=t[i+1][j] + 1;
            }
            else
            max1=0;
            if (arr[i][j]>arr[i][j+1])
            {
                max2=t[i][j+1] + 1;
            }
            else
            max2=0;
            t[i][j]=max({max1, max2, 1});
            maxi=max({t[i+1][j], t[i][j+1], maxi});
            //cout<<maxi<<" ";
        }
        
    }
    /*for (int i = 0; i < m; i++)
    {
        cout<<endl;
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        
    }*/
    /*for (int i = 0; i <= m; i++)
    {
        cout<<endl;
        for (int j = 0; j <= n; j++)
        {
            cout<<t[i][j]<<" ";
        }
        
    }*/
    cout<<"The maximum length is: "<<maxi;
}