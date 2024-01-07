#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n;
int tsp[N][N];
int come[N]; // da co thanh pho nao di den i chua
int go[N];   // tu i da di den thanh pho nao chua
int nextCity[N];
int visited[N];
vector<pair<int, int>> city;
queue<pair<int, int>> q;
int p[N];
int r[N];
int find(int u)
{
    if (u == p[u])
        return u;
    p[u] = find(p[u]);
    return p[u];
}
void unify(int x, int y)
{
    // p[x] = y;
    p[y] = x;
}
void findMinRoute()
{
    loop(i, 1, n)
    {
        p[i] = i;
        r[i] = 1;
    }
    memset(come, 0, sizeof(come));
    memset(go, 0, sizeof(go));
    pair<int, int> v;
    int vf, vs;
    int count = 0;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        vf = v.first;
        vs = v.second;
        if (!go[vf] && !come[vs])
        {
            int pvf = find(vf);
            int pvs = find(vs);

            if (pvf != pvs)
            {
                unify(pvf, pvs);
                nextCity[vf] = vs;
                go[vf] = 1;
                come[vs] = 1;
                count++;
                if (count == n - 1)
                    break;
            }
        }
    }

    int x = 1;
    x = find(x);
    int y = 0;
    int Fmin = INT_MAX;
    int indexMin;
    int mark[N];
    while (1)
    {
        y++;
        mark[y] = x;
        cout << x << " ";

        visited[x] = 1;
        if (y == n)
            break;
        x = nextCity[x];
    }
    // int sum = 0;
    // loop(i, 1, n - 1)
    // {
    //     sum += tsp[mark[i]][mark[i + 1]];
    // }
    // sum += tsp[mark[n]][mark[1]];
    // cout << "\nSum: " << sum << endl;
}
bool compare(pair<int, int> a, pair<int, int> b)
{
    return tsp[a.first][a.second] < tsp[b.first][b.second];
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    cout << n << "\n";
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> tsp[i][j];
            if (tsp[i][j] == 0)
                tsp[i][j] = INT_MAX;
            if (i != j)
                city.push_back(make_pair(i, j));
        }
    }
    sort(city.begin(), city.end(), compare);
    loop(i, 0, n * (n - 1) - 1)
    {
        q.push(city[i]);
    }

    findMinRoute();
}
