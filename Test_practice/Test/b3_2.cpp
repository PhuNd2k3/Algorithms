#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
long long int n, m;
long long int a[N][N];
long long int c[N][N];

void input()
{
    cin >> n;
    cin >> m;
    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            cin >> a[i][j];
        }
    }
}

void khobau()
{
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            c[i][j] = INT_MAX;
        }
    }
    c[1][1] = a[1][1];
    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            if (i == 1 && j == 1)
                continue;
            if (a[i][j] != 0)
            {

                if (c[i - 1][j] != INT_MAX)
                {
                    c[i][j] = min(c[i][j], c[i - 1][j] + a[i][j]);
                }
                if (c[i][j - 1] != INT_MAX)
                {
                    c[i][j] = min(c[i][j], c[i][j - 1] + a[i][j]);
                }
                if (c[i - 1][j - 1] != INT_MAX)
                {
                    c[i][j] = min(c[i][j], c[i - 1][j - 1] + a[i][j]);
                }
            }
        }
    }
    if (c[n][m] != INT_MAX)
        cout << c[n][m];
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    khobau();
    return 0;
}