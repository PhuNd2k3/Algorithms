#include <bits/stdc++.h>
#define N 100001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
struct Edge
{
    int u, v;
    long long int w;
};
Edge E[N];
int n, m;
int p[N]; // luu nut cha cua v
int r[N]; // luu do cao cua v
int compare(Edge x, Edge y)
{
    return x.w < y.w;
}
void input()
{
    cin >> n >> m;
    loop(i, 1, m)
    {
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E + 1, E + 1 + m, compare);
    loop(i, 1, m)
    {
        cout << E[i].u << " " << E[i].v << endl;
    }
    cout << endl;
}

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
vector<Edge> T;

long long int Krusal()
{
    long long int W = 0;
    loop(v, 1, n)
    {
        p[v] = v;
        r[v] = 1;
    }
    int u, v;
    loop(i, 1, m)
    {
        u = find(E[i].u);
        v = find(E[i].v);
        if (u != v)
        {
            W += E[i].w;
            T.push_back(E[i]);
            unify(u, v);
            if (T.size() == n - 1) // cay n dinh co n-1 canh
                break;
        }
    }
    return W;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    cout << Krusal();
    cout << endl;
    // loop(i, 1, n)
    // {
    //     cout << r[i] << " ";
    // }
    return 0;
}