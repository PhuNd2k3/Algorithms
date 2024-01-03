#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int m;
int num[N];
int low[N];
vector<int> g[N];
int turn = 0;
stack<int> s;
// int inStacks[N];
int visited[N];
int nbCC = 0;
vector<int> SCC[N];
void input()
{
    cin >> n >> m;
    int v1, v2;
    loop(i, 1, m)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }
}
void dfs(int u)
{
    turn++;
    num[u] = turn;
    low[u] = num[u];
    s.push(u);

    for (int &e : g[u])
    {
        if (visited[e])
            continue;
        if (num[e] > 0)
        {

            low[u] = min(low[u], num[e]);
        }
        else
        {
            dfs(e);
            low[u] = min(low[u], low[e]);
        }
    }
    int tmp;
    if (low[u] == num[u])
    {
        nbCC++;
        do
        {
            tmp = s.top();
            s.pop();
            SCC[nbCC].push_back(tmp);
            visited[tmp] = 1;
        } while (tmp != u);
    }
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
        if (!num[i])
            dfs(i);
    }
    cout << nbCC << endl;
    return 0;
}