#include <iostream>
using namespace std;
int main()
{
    string num1;
    string num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
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
    for (int i = 0; i < num1.length() + num2.length(); i++)
    {
        cout << mul[i];
    }
    cout << endl;
}