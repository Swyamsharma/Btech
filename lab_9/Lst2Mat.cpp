#include <iostream>
#include <vector>
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
bool IsEdge(int a, int b, Node *ptr[])
{

    struct Node *ptra = ptr[a];
    struct Node *ptrb = ptr[b];
    while (ptra != NULL && ptrb != NULL)
    {
        if (ptra->data == b || ptrb->data == a)
            return true;
        else
        {
            ptra = ptra->next;
            ptrb = ptrb->next;
        }
    }
    return false;
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
void DeleteEdge(struct Node *adjlst[], int a, int b)
{
    struct Node *ptra = adjlst[a]->next;
    struct Node *ptra1 = adjlst[a];
    struct Node *ptrb = adjlst[b]->next;
    struct Node *ptrb1 = adjlst[b];
    while (ptra != NULL)
    {
        if (ptra->data == b)
        {
            ptra1->next = ptra->next;
            delete ptra;
            break;
        }
        else
        {
            ptra = ptra->next;
            ptra1 = ptra1->next;
        }
    }
    while (ptrb != NULL)
    {
        if (ptrb->data == a)
        {
            ptrb1->next = ptrb->next;
            delete ptrb;
            break;
        }
        else
        {
            ptrb = ptrb->next;
            ptrb1 = ptrb1->next;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of nodes.\n";
    cin >> n;
    Node *adjlst[n];
    for (int i = 0; i < n; i++)
    {
        adjlst[i] = GETSIZE;
        adjlst[i]->data = i;
    }
    struct Node *ptr;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the connecting nodes of " << i << " .\n";
        cout << "Enter -1 to stop.\n";
        ptr = adjlst[i];
        while (1)
        {
            int temp;
            cin >> temp;
            if (temp != -1)
            {
                ptr->next = GETSIZE;
                ptr->next->data = temp;
                ptr = ptr->next;
            }
            else
            {
                ptr->next = NULL;
                break;
            }
        }
    }
    vector<vector<int>> adjmat(n, vector<int>(n, 0));
    int choice = 0;
    while (choice != 6)
    {
        cout << "\n1. Check edge.\n2. Insert edge.\n3. list all edge.\n4. delete edge.\n5. Add new node.\n6. Convert Adjacency Matrix to Adjacency List.\n7. Exit.\n";
        cin >> choice;
        int a, b;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the nodes: ";
            cin >> a >> b;
            if (IsEdge(a, b, adjlst))
                cout << "Edge exists." << endl;
            else
                cout << "Edge doesn't exists." << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the nodes: ";
            cin >> a >> b;
            if (IsEdge(a, b, adjlst))
            {
                cout << "Edge already exists." << endl;
            }
            else
            {
                adjlst[a] = InsertEdge(adjlst[a], b);
                adjlst[b] = InsertEdge(adjlst[b], a);
                cout << "Edge inserted" << endl;
            }
            break;
        }
        case 3:
        {
            cout << endl;
            DisplayEdges(adjlst, n);
            break;
        }
        case 4:
            cout << "Enter the nodes: ";
            cin >> a >> b;
            if (IsEdge(a, b, adjlst))
            {
                DeleteEdge(adjlst, a, b);
                cout << "Edge Deleted Successfully." << endl;
            }
            else
                cout << "There is no edge between the given nodes." << endl;
            break;
        case 5:
            cout << "Enter the connecting nodes of " << n << " .\n";
            cout << "Enter -1 to stop.\n";
            adjlst[n] = GETSIZE;
            ptr = adjlst[n];
            adjlst[n]->data = n;
            while (1)
            {
                int temp;
                cin >> temp;
                if (temp != -1)
                {
                    ptr->next = GETSIZE;
                    ptr->next->data = temp;
                    ptr = ptr->next;
                    adjlst[temp] = InsertEdge(adjlst[temp], n);
                }
                else
                {
                    ptr->next = NULL;
                    break;
                }
            }
            n++;
            cout << "New node is added." << endl;
            break;
        case 6:
            for (int i = 0; i < n; i++)
            {
                ptr = adjlst[i]->next;
                while (ptr != NULL)
                {
                    adjmat[i][ptr->data] = 1;
                    ptr = ptr->next;
                }
            }
            break;
        }
    }
}