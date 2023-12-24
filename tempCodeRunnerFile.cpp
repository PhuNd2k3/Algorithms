///$ HA DUY BACH 20210093 - HUST
#include <bits/stdc++.h>
#define _name "test"
#define _start                                  \
    {                                           \
        ios_base::sync_with_stdio(false);       \
        cin.tie(0);                             \
        cout.tie(0);                            \
        if (fopen(_name ".inp", "r"))           \
        {                                       \
            freopen(_name ".inp", "r", stdin);  \
            freopen(_name ".out", "w", stdout); \
        }                                       \
    }
#define _testGenerator                          \
    {                                           \
        if (fopen(_name ".inp", "w"))           \
        {                                       \
            freopen(_name ".inp", "w", stdout); \
        }                                       \
    }
#define ww cout << '\n';
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define p4i pair<pii, pii>
#define fi first
#define se second
#define pb push_back
#define getbit(a, n) ((a >> n) & 1)
#define onbit(a, n) (a | (1 << n))
#define offbit(a, n) (a & (~(1 << n)))
#define MAXINT 2147483647
using namespace std;
const int N = 1005;

int n, m, f[N][N], a[N][N];

int main()
{
    _start;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        f[i][0] = MAXINT;
    }

    for (int j = 1; j <= m; j++)
    {
        f[0][j] = MAXINT;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            f[i][j] = MAXINT;

            if (i == 1 && j == 1)
            {
                f[i][j] = a[i][j];
                continue;
            }

            if (a[i][j] == 0)
                continue;

            if (f[i - 1][j] != MAXINT)
            {
                f[i][j] = min(f[i][j], f[i - 1][j] + a[i][j]);
            }
            if (f[i][j - 1] != MAXINT)
            {
                f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
            }
            if (f[i - 1][j - 1] != MAXINT)
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + a[i][j]);
            }
        }
    }

    //    for (int i =1; i<=n; i++)
    //    {
    //        for (int j =1; j<=m; j++)
    //        {
    //            cout<<f[i][j]<<" ";
    //        }
    //        cout<<'\n';
    //    }

    cout << ((f[n][m] == MAXINT) ? -1 : f[n][m]);
}