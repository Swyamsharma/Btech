//brute force
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cost(int p[], int s, int e)
{
    int cost1=0;
    int min=INT_MAX;
    if (s==e)
    return 0;
    for (int i = s; i < e; i++)
    {
        cost1=cost(p, s, i) + cost(p, i+1, e) + p[s - 1]*p[i]*p[e];
        if (cost1<min)
        {
            min=cost1;
        }
        
    }
    return min;
}
int main()
{
    int n;
    cout<<"Enter the number of Matrices: ";
    cin>>n;
    int p[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin>>p[i];
    }
    
    cout<<"Least number of steps: "<<cost(p, 1, n);
}