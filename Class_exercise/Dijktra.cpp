#include <bits/stdc++.h>
#define N 100001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define pii pair<int, int>

using namespace std;
int n, m;
int s, t;
long long int d[N];
int p[N];
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
vector<Arc> a[N];
void input()
{
    int u, v, w;
    cin >> n >> m;
    loop(i, 1, m)
    {
        cin >> u >> v >> w;
        a[u].push_back(Arc(v, w));
    }
    cin >> s >> t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    loop(i, 1, n)
    {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, s));
    int u, v, w;
    pii e;
    while (!pq.empty())
    {
        e = pq.top();
        pq.pop();
        u = e.second;
        if (u == t)
            break;
        for (Arc i : a[u])
        {
            v = i.node;
            w = i.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push(make_pair(d[v], v));
                p[v] = u;
            }
        }
    }
    if (d[t] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        // stack<int> st;
        // v = t;
        // while (v != s)
        // {
        //     // cout << v << " ";
        //     st.push(v);
        //     v = p[v];
        // }
        // cout << v << " ";
        // while (!st.empty())
        // {
        //     v = st.top();
        //     st.pop();
        //     cout << v << " ";
        // }
        // cout << endl;
        cout << d[t];
    }
    return 0;
}