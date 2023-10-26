#include <iostream>
#include <vector>
using namespace std;
long long int fib(int n, vector<long long int>TD)
{
    if (n==0||n==1)
    {
        return n;
    }
    else if (TD[n]!=0)
    {
        return TD[n];
    }
    else
    return TD[n]=fib(n-1, TD) + fib(n-2, TD);
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<long long int>TD(n+1);
    cout<<fib(n, TD);
}