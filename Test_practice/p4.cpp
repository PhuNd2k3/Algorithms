#include <bits/stdc++.h>
#define N 5001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define piii pair<int, pair<int, int>>

using namespace std;
int n, m, d, k;
vector<int> arc[N];
int w[N][N];
int p[N]; // luu nut cha cua v
int r[N]; // luu do cao cua v
int find(int v)
{
    if (v == p[v])
        return v;
    p[v] = find(p[v]);
    return p[v];
}

void unify(int x, int y)
{
    if (r[x] > r[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if (r[x] == r[y])
            r[y]++;
    }
}
int umin, vmin, wmin = INT_MAX;
void input()
{
    cin >> n >> m >> d >> k;
    int u, v;
    loop(i, 1, m)
    {
        cin >> u >> v;
        cin >> w[u][v];
        w[v][u] = w[u][v];
        arc[u].push_back(v);
        arc[v].push_back(u);
        if (w[u][v] < wmin)
        {
            wmin = w[u][v];
            umin = u;
            vmin = v;
        }
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
void greedy()
{
    loop(v, 1, n)
    {
        p[v] = v;
        r[v] = 1;
    }
    set<int> s;
    s.insert(umin);
    s.insert(vmin);
    for (int e : arc[umin])
        pq.push({w[umin][e], {umin, e}});
    for (int e : arc[vmin])
        pq.push({w[vmin][e], {vmin, e}});

    int degree[N]; // bac tai dinh i
    degree[umin]++;
    degree[vmin]++;
    unify(umin, vmin);
    cout << k << endl;
    cout << umin << " " << vmin << endl;

    int f = 1; // current edge
    while (f < k)
    {
        piii e = pq.top();
        pq.pop();
        int u = e.second.first;
        int v = e.second.second;
        if (degree[u] == d || degree[v] == d)
            continue;
        int pu = find(u);
        int pv = find(v);

        if (pu != pv)
        {
            unify(pu, pv);
            // loop(i, 1, n)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            // loop(i, 1, n)
            // {
            //     cout << p[i] << " ";
            // }
            // cout << endl;

            s.insert(u);
            s.insert(v);
            degree[u]++;
            degree[v]++;
            cout << u << " " << v << endl;
            for (int i : arc[u])
            {
                pq.push({w[u][i], {u, i}});
            }
            for (int i : arc[v])
            {
                pq.push({w[v][i], {v, i}});
            }
            f++;
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
    greedy();
    return 0;
}