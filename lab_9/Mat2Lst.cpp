#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define GETSIZE (struct Node *)malloc(sizeof(struct Node))
struct Node
{
    int data;
    struct Node *next;
};
struct Node *InsertEdge(struct Node *ptr, int x)
{
    struct Node *p = GETSIZE;
    p->data = x;
    p->next = ptr->next;
    ptr->next = p;
    return ptr;
}
void DisplayEdges(struct Node *adjlst[], int n)
{

    struct Node *ptr;
    for (int i = 0; i < n; i++)
    {
        ptr = adjlst[i]->next;
        while (ptr != NULL)
        {
            cout << "(" << adjlst[i]->data << ", " << ptr->data << ") ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
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
    Node *adjlst[n];
    Node *ptr;
    int choice = 0;
    while (choice != 7)
    {
        cout << "1. Check edge.\n2. Insert edge.\n3. list all edge.\n4. delete edge.\n5. Add new node.\n6. Convert the Adjacency Matrix to Adjacency List.\n7. Exit\n";
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
            cout << endl;
            for (int i = 0; i < adjmat.size(); i++)
            {
                for (int j = 0; j < adjmat.size(); j++)
                {
                    if (adjmat[i][j] == 1)
                    {
                        cout << "(" << i << ", " << j << ")";
                    }
                }
            }
            break;
        case 4:
            cout << "Enter the nodes: ";
            cin >> a >> b;
            if (adjmat[a][b] || adjmat[b][a])
            {
                adjmat[a][b] = 0;
                adjmat[b][a] = 0;
            }
            else
                cout << "There is no edge between the given nodes." << endl;
            break;
        case 5:
            adjmat.push_back(vector<int>(n, 0));
            for (int i = 0; i < n + 1; i++)
            {
                adjmat[i].push_back(0);
            }
            n++;
            cout << "New node is added.";
        case 6:
            for (int i = 0; i < n; i++)
            {
                adjlst[i] = GETSIZE;
                adjlst[i]->data = i;
                ptr = adjlst[i];
                for (int j = 0; j < n; j++)
                {
                    if (adjmat[i][j] == 1)
                    {
                        ptr->next = GETSIZE;
                        ptr = ptr->next;
                        ptr->data = j;
                    }
                }
                ptr->next = NULL;
            }
            break;
        default:
            break;
        }
    }
    DisplayEdges(adjlst, n);
}