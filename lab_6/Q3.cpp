#include <iostream>
#include <vector>
using namespace std;
long long int fib(int n)
{
    vector<long long int> fibtable(n + 1);
    fibtable[0] = 0;
    fibtable[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibtable[i] = fibtable[i - 1] + fibtable[i - 2];
    }
    return (fibtable[n]);
}
int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<fib(n);
}