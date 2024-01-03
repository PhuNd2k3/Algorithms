#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int m;
vector<int> g[N];
vector<int> gt[N];
int nbCC = 0;
vector<int> SCC[N];
stack<int> s;
bool visited[N];
void input()
{
    cin >> n >> m;
    int v1, v2;
    loop(i, 1, m)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        gt[v2].push_back(v1);
    }
    // for (auto it = g[1].begin(); it != g[1].end(); it++)
    // {
    //     cout << *it << endl;
    //     // }
    // }
}

void dfs1(int v)
{
    // cout << v << endl;
    visited[v] = true;
    // for (int e : g[v])
    for (auto it = g[v].begin(); it != g[v].end(); it++)
    {
        if (!visited[*it])
        {
            dfs1(*it);
            // cout << *it << endl;
        }
    }
    s.push(v);
}

void dfs2(int v)
{
    // cout << v << " ";
    visited[v] = true;
    SCC[nbCC].push_back(v);
    for (auto it = gt[v].begin(); it != gt[v].end(); it++)
    {
        if (!visited[*it])
        {
            dfs2(*it);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    input();
    dfs1(1);
    loop(i, 0, N - 1)
    {
        visited[i] = false;
    }
    int v;

    while (!s.empty())
    {
        v = s.top();
        s.pop();
        if (!visited[v])
        {
            nbCC++;
            // cout << "NBCC " << nbCC << ": ";
            dfs2(v);
            // cout << endl;
        }
    }
    cout << nbCC;
    return 0;
}