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
            // if (a[i][j] == 0)
            //     a[i][j] = INT_MAX;
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
}

void khobau()
{
    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            c[i][j] = INT_MAX;
        }
    }
    c[1][1] = a[1][1];
    loop(i, 2, n)
    {
        if (a[i][1] != 0)
            if (c[i - 1][1] != INT_MAX)
                c[i][1] = c[i - 1][1] + a[i][1];
        // cout << c[i][1] << endl;
    }
    loop(i, 2, m)
    {
        if (a[1][i] != 0)
            if (c[1][i - 1] != INT_MAX)
            {
                c[1][i] = c[1][i - 1] + a[1][i];
            }
        // cout << c[1][i] << " ";
    }
    // cout << endl;
    loop(i, 2, n)
    {
        loop(j, 2, m)
        {
            if (a[i][j] != 0)
            {
                // if (c[i][j - 1] != INT_MAX && c[i - 1][j] != INT_MAX && c[i - 1][j - 1] != INT_MAX)
                // {
                //     c[i][j] = min(min(c[i - 1][j], c[i][j - 1]), c[i - 1][j - 1]) + a[i][j];
                //     continue;
                // }
                // if (c[i - 1][j] != INT_MAX && c[i][j - 1] != INT_MAX)
                // {
                //     c[i][j] = min(c[i - 1][j], c[i][j - 1]) + a[i][j];
                //     continue;
                // }
                // if (c[i - 1][j] != INT_MAX && c[i - 1][j - 1] != INT_MAX)
                // {
                //     c[i][j] = min(c[i - 1][j], c[i - 1][j - 1]) + a[i][j];
                //     continue;
                // }
                // if (c[i][j - 1] != INT_MAX && c[i - 1][j - 1] != INT_MAX)
                // {
                //     c[i][j] = min(c[i][j - 1], c[i - 1][j - 1]) + a[i][j];
                //     continue;
                // }
                // if (c[i - 1][j] != INT_MAX)
                // {
                //     c[i][j] = c[i - 1][j] + a[i][j];
                //     continue;
                // }
                // if (c[i][j - 1] != INT_MAX)
                // {
                //     c[i][j] = c[i][j - 1] + a[i][j];
                //     continue;
                // }
                // if (c[i - 1][j - 1] != INT_MAX)
                // {
                //     c[i][j] = c[i - 1][j - 1] + a[i][j];
                //     continue;
                // }

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