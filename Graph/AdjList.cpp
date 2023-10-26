#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define GETSIZE (struct Node *)malloc(sizeof(struct Node))
struct Node
{
    int data;
    struct Node *next;
};
static struct Node *Front = NULL;
static struct Node *Rear = NULL;
static struct Node *Top = NULL;
struct Node *InsertEdge(struct Node *ptr, int x)
{
    struct Node *p = GETSIZE;
    p->data = x;
    p->next = ptr->next;
    ptr->next = p;
    return ptr;
}
bool IsEdge(int a, int b, struct Node *ptr[])
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
void Push(int data1)
{
    struct Node *ptr = GETSIZE;
    ptr->data = data1;
    if (Top == NULL)
        Top = ptr;
    else
    {
        ptr->next = Top;
        Top = ptr;
    }
}
int Pop()
{
    if (Top == NULL)
        return -1;
    struct Node *ptr = Top;
    int Val = ptr->data;
    Top = Top->next;
    delete ptr;
    return Val;
}
void Enqueue(int data)
{
    struct Node *newNode = GETSIZE;
    newNode->data = data;
    newNode->next = NULL;
    if (Front == NULL)
    {
        Rear = newNode;
        Front = Rear;
    }
    else
    {
        Rear->next = newNode;
        Rear = newNode;
    }
}

int Dequeue()
{
    Node *ptr = Front;
    int el = ptr->data;
    Front = Front->next;
    delete ptr;
    return el;
}
bool IsEmpty()
{
    if (Front == NULL)
    {
        return true;
    }
    return false;
}
vector<pair<int, int>> advDFS(struct Node *adjlst[], int n)
{
    struct Node *ptr;
    int Explored[n];
    for (int i = 0; i < n; i++)
    {
        Explored[i] = 0;
    }
    vector<pair<int, int>> time(n);
    int count = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!Explored[i])
        {
            int parent[n];
            for (int j = 0; j < n; j++)
            {
                parent[j] = -1;
            }
            Push(i);
            while (Top != NULL)
            {
                int temp = Top->data;
                if (!Explored[temp])
                {
                    Explored[temp] = 1;
                    time[temp].first = count++;
                    cout << temp << " ";
                }
                bool allneighboursvisited = true;
                ptr = adjlst[temp]->next;
                while (ptr != NULL)
                {
                    if (!Explored[ptr->data])
                    {
                        Push(ptr->data);
                        parent[ptr->data] = temp;
                        allneighboursvisited = false;
                        break;
                    }
                    ptr = ptr->next;
                }
                if (allneighboursvisited)
                {
                    time[Pop()].second = count++;
                }
            }
            for (int j = 0; j < n; j++)
            {
                if (parent[j] != -1)
                {
                    cout << "Parent of " << j << " is " << parent[j];
                }
            }
        }
    }
    return time;
}
struct Node *Reverse(struct Node *adjlst[], int n, struct Node *adjlst1[])
{
    for (int i = 0; i < n; i++)
    {
        adjlst1[i] = GETSIZE;
        adjlst1[i]->data = i;
        adjlst1[i]->next = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        struct Node *ptr = adjlst[i]->next;
        while (ptr != NULL)
        {
            adjlst1[ptr->data] = InsertEdge(adjlst1[ptr->data], i);
            ptr = ptr->next;
        }
    }
    return *adjlst1;
}
void DFS(struct Node *adjlst[], int n, int startNode, int visited[])
{ 
    struct Node *ptr;
    stack<int> s;
    s.push(startNode);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            cout<<current<<" ";
            visited[current] = 1;
            ptr = adjlst[current]->next;
            while (ptr != NULL)
            {
                if (!visited[ptr->data])
                {
                    s.push(ptr->data);
                }
                ptr = ptr->next;
            }
        }
    }
}
bool Bipartite(struct Node *adjlst[], int n, int s)
{
    int Explored[n];
    for (int i = 0; i < n; i++)
    {
        Explored[i] = 0;
    }
    struct Node *ptr;
    Enqueue(s);
    while (IsEmpty() == 0)
    {
        ptr = adjlst[Dequeue()]->next;
        while (ptr != NULL)
        {
            struct Node *ptr1 = ptr;
            while (ptr1->next != NULL)
            {
                if (IsEdge(ptr->data, ptr1->next->data, adjlst))
                {
                    return false;
                }
                ptr1 = ptr1->next;
            }
            if (Explored[ptr->data] == 0)
            {
                Explored[ptr->data] = 1;
                Enqueue((ptr->data));
            }
            ptr = ptr->next;
        }
    }
    return true;
}
bool Connectivity_BFS(struct Node *adjlst[], int n, int s)
{
    int Explored[n];
    for (int i = 0; i < n; i++)
    {
        Explored[i] = 0;
    }
    struct Node *ptr;
    Enqueue(s);
    while (IsEmpty() == 0)
    {
        ptr = adjlst[Dequeue()]->next;
        while (ptr != NULL)
        {
            if (Explored[ptr->data] == 0)
            {
                Explored[ptr->data] = 1;
                Enqueue((ptr->data));
                cout << ptr->data << " ";
            }
            ptr = ptr->next;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (Explored[i] == 0)
            return 0;
    }
    return 1;
}
int Distance(struct Node *adjlst[], int n, int src, int key)
{
    int Distance[n];
    struct Node *ptr;
    for (int i = 0; i < n; i++)
    {
        Distance[i] = INT_MAX;
    }
    Distance[src] = 0;
    Enqueue(src);
    while (!IsEmpty())
    {
        int node = Front->data;
        ptr = adjlst[Dequeue()]->next;
        while (ptr != NULL)
        {
            for (int i = 0; i <= ptr->data; i++)
            {
                if (Distance[node] + 1 < Distance[i])
                {
                    Distance[i] = Distance[node] + 1;
                    Enqueue(i);
                }
            }
            ptr = ptr->next;
        }
    }
    int Ans[n];
    for (int i = 0; i < n; i++)
    {
        if (Distance[i] != INT_MAX)
        {
            Ans[i] = Distance[i];
        }
        else
            Ans[i] = -1;
    }
    return Ans[key];
}
int Diameter(struct Node *adjlst[], int n)
{
    int maxi = 0;
    for (int src = 0; src < n; src++)
    {
        int Distance[n];
        struct Node *ptr;
        for (int i = 0; i < n; i++)
        {
            Distance[i] = INT_MAX;
        }
        Distance[src] = 0;
        Enqueue(src);
        while (!IsEmpty())
        {
            int node = Front->data;
            ptr = adjlst[Dequeue()]->next;
            while (ptr != NULL)
            {
                if (Distance[ptr->data] == INT_MAX)
                {
                    Distance[ptr->data] = Distance[node] + 1;
                    Enqueue(ptr->data);
                }
                ptr = ptr->next;
            }
        }
        int maxi1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (Distance[i] != INT_MAX && Distance[i] > maxi1)
                maxi1 = Distance[i];
        }
        if (maxi1 > maxi)
            maxi = maxi1;
    }
    return maxi;
}
void FintimeDFS(struct Node *adjlst[], int n, int s, int visited[])
{
    visited[s] = true;
    struct Node *ptr;
    ptr = adjlst[s]->next;
    while (ptr != NULL)
    {
        if (!visited[ptr->data])
        {
            FintimeDFS(adjlst, n, ptr->data, visited);
        }
        ptr = ptr->next;
    }
    Push(s);
}
int SCC(struct Node *adjlst[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    FintimeDFS(adjlst, n, 0, visited);
    struct Node *adjlst1[n];
    *adjlst1 = Reverse(adjlst, n, adjlst1);
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    struct Node *ptr;
    int count = 0;
    while (Top != NULL)
    {
        if (!visited[Top->data])
        {
            DFS(adjlst1, n, Top->data, visited);
            cout<<endl;
            count++;
        }
        else
            Pop();
    }
    return count;
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
    int s;
    int choice = 0;
    while (choice != 10)
    {
        cout << "\n1. Check edge.\n2. Insert edge.\n3. list all edge.\n4. delete edge.\n5. Add new node.\n6. Check Connectivity.\n7. Bipartite.\n8. Diameter.\n9. Strongly Connected Components\n10. Exit\n";
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
            cout << "Enter the node: ";
            cin >> s;
            if (Connectivity_BFS(adjlst, n, s))
                cout << "Connected." << endl;
            else
                cout << "NOT Connected." << endl;
            break;
        case 7:
            if (Bipartite(adjlst, n, 0))
            {
                cout << "The graph is bipartite.";
            }
            else
                cout << "The graph is not bipartite.";
            break;
        case 8:
            cout << Diameter(adjlst, n);
            break;
        case 9:
            int temp = SCC(adjlst, n);
            cout<<"No. of Connected Components: "<<temp;
            break;
        }
    }
}