#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string mult(string num1, string num2)
{
    int mul[num1.length() + num2.length()] = {0};
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                mul[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                mul[i + j] += mul[i + j + 1] / 10;
                mul[i + j + 1] = mul[i + j + 1] % 10;
            }
        }
        string m;
    for(int x : mul)
    {
        m += to_string(x);
    }
    return m;
}
string factorial(int n)
{
    string result = "1";

    for (int i = 2; i <= n; i++)
    {
        result = mult(result, to_string(i));
    }
    int start = 0;
    while (start < result.length() && result[start] == '0')
    {
        start++;
    }
    if (start == result.length())
    {
        result = "0";
    }
    else
    {
        result = result.substr(start);
    }

    return result;
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    string mul = factorial(n);
    cout<<"If there is no tie, then: "<<mul<<" possible outcomes."<<endl;
    
}