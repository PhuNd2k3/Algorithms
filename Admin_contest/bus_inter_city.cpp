#include <bits/stdc++.h>
#define N 5001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>

using namespace std;
int n, m;
int cost[N];
int d[N];
vector<int> arc[N];

int weight[N][N];
void input()
{
    cin >> n;
    cin >> m;
    int tmp1;
    int tmp2;
    loop(i, 1, n)
    {
        cin >> tmp1;
        cin >> tmp2;
        cost[i] = tmp1;
        d[i] = tmp2;
    }
    loop(i, 1, m)
    {
        cin >> tmp1;
        cin >> tmp2;
        arc[tmp1].push_back(tmp2);
        arc[tmp2].push_back(tmp1);
    }
}
void BFS(int k)
{
    queue<int> Q;
    int f[N];
    loop(i, 1, n)
    {
        f[i] = -1;
    }
    Q.push(k);
    f[k] = 0;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        weight[k][v] = cost[k];
        for (int u : arc[v])
        {
            if (f[u] >= 0)
                continue;
            f[u] = f[v] + 1;
            if (f[u] <= d[k])
            {
                Q.push(u);
            }
        }
    }
}

void build_G()
{
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            weight[i][j] = INT_MAX;
        }
    }
    loop(i, 1, n)
    {
        BFS(i);
    }
}
void dijktra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // sap xep the first
    pq.push(make_pair(0, 1));
    // min cost to city 1 is 0
    int f[N];
    loop(i, 1, n)
    {
        f[i] = INT_MAX;
    }
    f[1] = 0;

    int u, v, w;
    pii e;
    while (!pq.empty())
    {
        e = pq.top();
        pq.pop();
        u = e.second;
        if (u == n)
            break;
        loop(v, 1, n)
        {
            if (weight[u][v] != INT_MAX)
            {
                if (f[v] > f[u] + weight[u][v])
                {
                    f[v] = f[u] + weight[u][v];
                    pq.push(make_pair(f[v], v));
                }
            }
        }
    }
    cout << f[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    build_G();
    dijktra();
    return 0;
}