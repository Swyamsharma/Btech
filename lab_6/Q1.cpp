#include <iostream>
using namespace std;
int fib(int n)
{
    if (n==1)
        return 1;
    else if (n==0)   
        return 0; 
    else return fib(n-1) + fib(n-2);
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"The fibonacci element is: "<<fib(n);
}
