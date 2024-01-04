#include <bits/stdc++.h>
#define MAX_N 100001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
struct Arc
{
    int node;
    int w;
    Arc(int _node, int _w)
    {
        node = _node;
        w = _w;
    }
};
vector<Arc> a[MAX_N];

int N[MAX_N];
long long int d[MAX_N];
long long int f[MAX_N];
int visited[MAX_N];
void input()
{
    int u, v, w;
    cin >> n;
    loop(i, 1, n - 1)
    {
        cin >> u >> v >> w;
        a[u].push_back(Arc(v, w));
        a[v].push_back(Arc(u, w));
    }
    // for (Arc e : a[1])
    // {
    //     cout << e.node << " " << e.w << endl;
    // }
}
void dfs1(int u)
{
    N[u] = 1;
    d[u] = 0;
    visited[u] = 1;
    for (Arc e : a[u])
    {
        if (!visited[e.node])
        {
            dfs1(e.node);
            d[u] = d[u] + d[e.node] + e.w * N[e.node];
            N[u] += N[e.node];
        }
    }
}
void dfs2(int u)
{
    long long int F = 0;
    visited[u] = 1;
    int v, w;
    for (Arc e : a[u])
    {
        if (!visited[e.node])
        {
            v = e.node;
            w = e.w;
            F = f[u] - (d[v] + w * N[v]);
            f[v] = F + w * (n - N[v]) + d[v];
            dfs2(v);
        }
    }
}

void sumOfLengthPath()
{
    memset(visited, 0, sizeof(visited));
    dfs1(1);
    memset(visited, 0, sizeof(visited));
    f[1] = d[1];
    dfs2(1);
    cout << *max_element(f + 1, f + n + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    sumOfLengthPath();
    return 0;
}