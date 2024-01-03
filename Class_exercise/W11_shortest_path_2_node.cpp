#include <bits/stdc++.h>
#define N 100005
#define M 300005
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
int s, t;
long long int f = 0;
long long int Fmin = INT_MAX;
long long int d[N];
struct
{
    int u, v;
    int w;
} e[M];
void input()
{
    cin >> n >> m;
    int u, v, w;
    loop(i, 1, m)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    cin >> s >> t;
}

void bellmanFord()
{
    int u, v, w;
    loop(i, 1, n)
    {
        d[i] = INT_MAX;
    }
    d[s] = 0;
    int stop = 1;
    int count = 0;
    do
    {
        stop = 1;
        for (auto E : e)
        {
            u = E.u;
            v = E.v;
            w = E.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                stop = 0;
            }
        }
        count++;
        if (count == n - 1)
            break;
    } while (stop == 0);
    cout << (d[t] == INT_MAX ? -1 : d[t]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    bellmanFord();
    return 0;
}