#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int m;
vector<int> a[N];
bool visited[N];
int color[N];

int nbCC = 0;
int cc[N];

int check = 1;

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

void givecolor(int v, int e)
{
    if (color[v] == 1)
        color[e] = 2;
    if (color[v] == 2)
        color[e] = 1;
    // cout << "color " << v << ": " << color[v] << endl;
    // cout << "color " << e << ": " << color[e] << endl;
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 1;
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
            if (color[e] == 0)
            {
                givecolor(v, e);
            }
            else
            {
                if (color[v] == color[e])
                {
                    // cout << "return 0 because: color " << v << ": " << color[v] << endl;
                    // cout << "color " << e << ": " << color[e] << endl;
                    check = 0;
                    return;
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < N; i++)
    {
        color[i] = 0;
        visited[i] = false;
    }

    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    cout << check << endl;
    return 0;
}