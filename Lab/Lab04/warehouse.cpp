#include <bits/stdc++.h>
#define N 1001

using namespace std;

int n, T, D;
int a[N];
int t[N];
// int d[N];

int c[N][N]; // c[i][j] is max in time i if choose xj

void input()
{
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    for (int i = 1; i <= T; i++)
    {
        if (i >= t[1])
        {
            c[i][1] = a[1];
        }
        else
            c[i][1] = 0;
    }
    for (int Ti = 1; Ti <= T; Ti++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (Ti >= t[j])
                c[Ti][j] = a[j];
            for (int k = j - D > 0 ? j - D : 1; k <= j - 1; k++)
            {
                if (Ti >= t[j] + t[k])
                {
                    c[Ti][j] = max(c[Ti][j], a[j] + c[Ti - t[j]][k]);
                }
            }
        }
    }
    int Fmax = 0;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Fmax = max(Fmax, c[i][j]);
        }
    }
    cout << Fmax << endl;
    return 0;
}