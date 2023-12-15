#include <bits/stdc++.h>
#define N 1000001

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
    for (int i = 0; i < m; i++)
    {
        cin >> v1;
        cin >> v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    int v;
    while (!q.empty())
    {
        v = q.front();
        // cout << v << " ";
        q.pop();
        for (int e : a[v])
        {
            if (!visited[e])
            {
                visited[e] = true;
                q.push(e);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    n = min(n, 100000);
    m = min(m, 100000);
    int count = 0;
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}