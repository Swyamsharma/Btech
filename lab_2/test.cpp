#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        int flag=0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (i>0&&a[i]!=a[i-1])
            {
                flag=1;
            }
            
        }
        stable_sort(a, a+n);
        int r=-1;
        for (int i = 0; i < n-1; i++)
        {
            if (a[i]==a[i+1]&& i>0)
            {
                r=i;
            }
        }
        if (r==-1&&flag==1)
        {
            r=n/2;
        }
        else if (flag==0)
        {
            r=-1;
        }
        if(r!=-1){
        cout<<r<<" ";
        cout<<n-r<<endl;
        for (int i = 0; i < r; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for (int i = r; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else 
    cout<<"-1"<<endl;
    }
}