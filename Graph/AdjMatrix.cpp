#include <iostream>
#include <bits\stdc++.h>
using namespace std;
int main()
{
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    vector<vector<int>> adjmat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjmat[i][j];
        }
    }
    int choice=0;
    while (choice!=6)
    {
    cout << "1. Check edge.\n2. Insert edge.\n3. list all edge.\n4.delete edge.\n5. Add new node.\n 6 Exit.";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the nodes: ";
        int a, b;
        cin >> a >> b;
        if (adjmat[a][b] || adjmat[b][a])
        {
            cout << "Egde exists\n";
        }
        else
            cout << "Edge doesn't exist\n";
        break;
    case 2:
        cout << "Enter the nodes: ";
        cin >> a >> b;
        adjmat[a][b] = 1;
        adjmat[b][a] = 1;
        break;
    case 3:
        cout<<endl;
        for (int i = 0; i < adjmat.size(); i++)
        {
            for (int j = 0; j < adjmat.size(); j++)
            {
                if (adjmat[i][j]==1)
                {
                    cout<<"("<<i<<", "<<j<<")";
                }
                
            }
            
        }
        break;
    case 4:
        cout<<"Enter the nodes: ";
        cin>>a>>b;
        if (adjmat[a][b]||adjmat[b][a]){
        adjmat[a][b]=0;
        adjmat[b][a]=0;
        }
        else
        cout<<"There is no edge between the given nodes."<<endl;
        break;
    case 5:
        adjmat.push_back(vector<int>(n, 0));
        for (int i = 0; i < n+1; i++)
        {
            adjmat[i].push_back(0);
        }
        cout<<"New node is added.";
    default:
        break;
    }
    }
}