#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of nodes of an AVL tree: ";
    cin >> n;
    cout << "Minimum Height: ";
    cout << (int)log2(n) << endl;
    cout << "Maximum Height: ";
    cout << (int)(sqrt(2) * log2(n)) << endl;
}