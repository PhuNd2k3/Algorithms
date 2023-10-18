// CPP
#include <bits/stdc++.h>
using namespace std;
int n, m, r, c;
#define MAX 999 + 100
int A[MAX][MAX];
int parent[MAX][MAX];
int dist[MAX][MAX];
// vector<vector<int>> A;

int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};
typedef pair<int, int> ii;
queue<ii> qe;
void input()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }
}

bool isOut(int x, int y)
{
    return (x < 1 || x > n || y < 1 || y > m);
}
int solve()
{
    qe.push(ii(r, c));
    dist[r][c] = 0;
    A[r][c] = 1;
    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (isOut(x, y))
                return dist[u.first][u.second] + 1;
            if (!A[x][y])
            {
                dist[x][y] = dist[u.first][u.second] + 1;
                qe.push(ii(x, y));
                A[x][y] = 1;
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    cout << solve();
    return 0;
}