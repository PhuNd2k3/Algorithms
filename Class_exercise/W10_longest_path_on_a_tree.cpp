#include <bits/stdc++.h>
#define N 100001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
vector<pair<int, int>> E[N];
long long int longestPath = 0;
long long int curPath = 0;
int visited[N];
void input()
{
    cin >> n;
    int u, v, w;
    loop(i, 1, n - 1)
    {
        cin >> u >> v >> w;
        E[u].push_back(make_pair(v, w));
        E[v].push_back(make_pair(u, w));
    }
}
int longestIndex;
void dfs(int u)
{
    visited[u] = 1;
    for (pair<int, int> e : E[u])
    {
        if (!visited[e.first])
        {
            curPath += e.second;
            if (curPath > longestPath)
            {
                longestPath = curPath;
                longestIndex = e.first;
            }
            dfs(e.first);
            curPath -= e.second;
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
    dfs(1);
    longestPath = 0;
    memset(visited, 0, sizeof(visited));
    dfs(longestIndex);
    cout << longestPath;
    return 0;
}