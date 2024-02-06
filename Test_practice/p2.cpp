#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int t[N][N];
int n;
int f[N][N];
void input()
{
    int x, y;
    cin >> n;
    loop(i, 1, n)
    {
        cin >> x;
        cin >> y;
        cin >> t[x][y];
    }
}
void dp()
{
    f[1][1] = t[1][1];
    loop(i, 2, n)
    {
        f[1][i] = f[1][i - 1] + t[1][i];
        f[i][1] = f[i - 1][1] + t[i][1];
    }
    loop(i, 2, n)
    {
        loop(j, 2, n)
        {
            f[i][j] = max(f[i - 1][j - 1], max(f[i - 1][j], f[i][j - 1])) + t[i][j];
        }
    }
    // loop(i, 1, n)
    // {
    //     loop(j, 1, n)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // loop(i, 1, n)
    // {
    //     loop(j, 1, n)
    //     {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << f[n][n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    dp();
    return 0;
}