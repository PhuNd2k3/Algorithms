#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int n;
int m;
vector<int> a[N];
bool visited[N];

int nbCC = 0;
int cc[N];

void input()
{
    int v1, v2;
    cin >> n;
    cin >> m;
    loop(i, 0, m)
    {
        cin >> v1;
        cin >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }
    for (vector<int> e : a)
    {
        sort(e.begin(), e.end());
        // neu can giam dan sort(data.begin(), data.end(), greater<int>() );
    }
}

void dfs(int u)
{
    nbCC++;
    visited[u] = true;
    cc[u] = nbCC;
    cout << u << " ";
    for (int e : a[u])
    {
        if (!visited[e])
            dfs(e);
    }
}

int main()
{
    loop(i, 0, N) visited[i] = false;
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    return 0;
}
