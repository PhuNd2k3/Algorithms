// CPP
// Chua co truy vet
#include <bits/stdc++.h>
using namespace std;
int n, m;
#define MAX 10000 + 100
int s[MAX][MAX], x[MAX], y[MAX];

void input()
{
    cin >> n >> m;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> y[j];
    }
}

int longestCommonSubSeq()
{
    for (int i = 0; i <= n; i++)
    {
        s[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        s[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                // cout << "x[i] " << x[i] << " y[j] " << y[j] << endl;
                s[i][j] = s[i - 1][j - 1] + 1;
            }
            else
            {
                s[i][j] = max(s[i][j - 1], s[i - 1][j]);
            }
        }
    }
    return s[n][m];
}

int main()
{
    input();
    cout << longestCommonSubSeq();
    return 0;
}