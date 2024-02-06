#include <bits/stdc++.h>
#define N 50
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n, m;
int w[N][N];
using namespace std;
vector<int> a[N];
int r[N];
int k;
int s, t;
void input()
{
    cin >> n >> m;
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            if (i != j)
                w[i][j] = INT_MAX;
        }
    }
    int u, v;
    loop(i, 1, m)
    {
        cin >> u >> v;
        cin >> w[u][v];
        w[v][u] = w[u][v];
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> k;
    loop(i, 1, k)
    {
        cin >> r[i];
    }
}
int d[N][N];
int trace[N][N];
void print()
{
    cout << endl;

    loop(u, 1, n)
    {
        loop(v, 1, n)
        {
            cout << w[u][v] << " ";
        }
        cout << endl;
    }
    cout << endl;

    loop(u, 1, n)
    {
        loop(v, 1, n)
        {
            cout << d[u][v] << " ";
        }
        cout << endl;
    }
}
void Floyd_Warshall()
{
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            d[i][j] = w[i][j];
            trace[i][j] = i;
        }
    }
    loop(k, 1, n)
    {
        loop(u, 1, n)
        {
            loop(v, 1, n)
            {
                if (d[u][k] != INT_MAX && d[k][v] != INT_MAX)
                    if (d[u][v] > d[u][k] + d[k][v])
                    {
                        d[u][v] = d[u][k] + d[k][v];
                        trace[u][v] = trace[k][v];
                    }
            }
        }
    }
}
vector<int> trace_path(int u, int v)
{
    vector<int> path;
    while (v != u)
    { // truy vết ngược từ v về u
        path.push_back(v);
        v = trace[u][v];
    }
    path.push_back(u);

    reverse(path.begin(), path.end()); // cần reverse vì đường đi từ v ngược về u
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    return path;
}

bool check(int v, int k)
{
}

void solution()
{
}
void Try(int k)
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    // Floyd_Warshall();

    return 0;
}