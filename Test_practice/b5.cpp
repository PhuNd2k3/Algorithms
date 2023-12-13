#include <bits/stdc++.h>
#define N 1000

using namespace std;

int n;
int a[N];
int dis[N][N];
int m;
int priority[N][N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dis[i][j];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k, l;
        cin >> k;
        cin >> l;
        priority[k][l] = 1;
    }
}

int solve()
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[a[j]][a[i]])
            {
                return -1;
            }
            if (j == (i + 1))
                result += dis[a[i] - 1][a[j] - 1];
        }
    }
    result += dis[a[n - 1] - 1][a[0] - 1];
    return result;
}

int main()
{
    input();
    cout << solve();
    return 0;
}