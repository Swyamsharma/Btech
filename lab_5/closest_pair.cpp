#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool comparex(pair<int, int> &x, pair<int, int> &y)
{
    return x.first < y.first;
}
bool comparey(pair<int, int> &x, pair<int, int> &y)
{
    return x.second < y.second;
}
long long int Distance(pair<int, int> x, pair<int, int> y)
{
    long long int x1y1 = x.first - y.first;
    long long int x2y2 = x.second - y.second;
    return ((x1y1 * x1y1) + (x2y2 * x2y2));
}
pair<pair<int, int>, pair<int, int>> closest_pair(vector<pair<int, int>> P, vector<pair<int, int>> Px, vector<pair<int, int>> Py, int low, int high)
{
    if (abs(high - low) <= 3)
    {
        long long int mini = INT_MAX;
        pair<pair<int, int>, pair<int, int>> Ans;
        for (int i = low; i <= high; i++)
        {
            for (int j = i + 1; j <= high; j++)
            {
                long long int length = Distance(Px[i], Px[j]);
                if (length < mini)
                {
                    mini = length;
                    Ans = {Px[i], Px[j]};
                }
            }
        }
        return Ans;
    }
    int mid = low + (high - low) / 2;
    pair<pair<int, int>, pair<int, int>> a, b;
    a = closest_pair(P, Px, Py, low, mid);
    b = closest_pair(P, Px, Py, mid + 1, high);

    long long int da = Distance(a.first, a.second);
    long long int db = Distance(b.first, b.second);
    long long int s = min(da, db);

    vector<pair<int, int>> Sy;
    for (int i = low; i <= high; i++)
        if (abs(Py[i].first - Px[mid].first) < s)
            Sy.push_back(Py[i]);
    int count = 0;
    for (int i = 0; i < Sy.size(); i++)
    {
        for (int j = i + 1; j < Sy.size() && (Sy[j].second - Sy[i].second) < s && count++ < 14; j++)
        {
            long long int dis = Distance(Sy[i], Sy[j]);
            if (dis < s)
            {
                s = dis;
                a = {Sy[i], Sy[j]};
            }
        }
    }
    return (da <= db) ? a : b;
}
int main()
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    vector<pair<int, int>> P(n, {0, 0});
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> t;
        P[i].first = t;
        cin >> t;
        P[i].second = t;
    }
    vector<pair<int, int>> Px = P;
    sort(Px.begin(), Px.end(), comparex);
    vector<pair<int, int>> Py = P;
    sort(Py.begin(), Py.end(), comparey);
    cout << "Px: ";
    for (int i = 0; i < n; i++)
    {
        cout << "{" << Px[i].first << ", " << Px[i].second << "}"
             << " ";
    }
    cout << endl
         << "Py: ";
    for (int i = 0; i < n; i++)
    {
        cout << "{" << Py[i].first << ", " << Py[i].second << "}"
             << " ";
    }
    cout << endl;
    pair<pair<int, int>, pair<int, int>> Ans = closest_pair(P, Px, Py, 0, P.size() - 1);
    pair<int, int>ans1=Ans.first, ans2=Ans.second;
    cout << "{" << ans1.first << ", " << ans1.second << "}"
         << " & "
         << "{" << ans2.first << ", " << ans2.second << "}" << endl;
}