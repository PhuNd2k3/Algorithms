#include <bits/stdc++.h>
#define N 5001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

using namespace std;
int n, m;
int c[N];
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
        c[i] = tmp1;
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
struct cmp
{
    bool operator()(piii const &a, piii const &b)
    {
        return a.first > b.first;
    }
};

priority_queue<piii, vector<piii>, cmp> pq;
void dijktra()
{
    pq.push({c[1], {1, d[1]}});
    int f[N];
    loop(i, 1, n)
    {
        f[i] = INT_MAX;
    }
    f[1] = 0;
    while (!pq.empty())
    {
        piii e = pq.top();
        pq.pop();
        int u = e.second.first;
        if (u == n)
        {
            cout << f[u];
            return;
        }
        int cost = e.first;
        int remain = e.second.second;
        for (int v : arc[u])
        {
            if (remain != 0 && f[v] > cost)
            {
                f[v] = cost;
                pq.push({cost, {v, remain - 1}});
            }
            else if (remain == 0)
            {
                if (f[v] > cost + c[u])
                { // len xe tai u
                    f[v] = cost + c[u];
                    pq.push({f[v], {v, d[u] - 1}});
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    dijktra();
    return 0;
}