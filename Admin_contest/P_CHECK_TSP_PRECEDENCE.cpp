#include <bits/stdc++.h>
#define N 10001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int d[N][N];
int m;
int a[N];
bool c[N][N];
bool visited[N];
void input()
{
    cin >> n;
    loop(i, 1, n) cin >> a[i];
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> d[i][j];
        }
    }
    cin >> m;
    int c1, c2;
    loop(j, 1, n)
    {
        cin >> c1;
        cin >> c2;
        c[c1][c2] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    int f = 0;
    loop(i, 1, n)
    {
        visited[i] = false;
        loop(j, 1, n) { c[i][j] = false; }
    }
    input();
    visited[a[1]] = true;
    loop(i, 2, n)
    {
        loop(j, 1, n)
        {
            if (!visited[j])
            {
                if (c[j][a[i]])
                {
                    // cout << a[i] << " " << j << endl;
                    cout << -1;
                    return 0;
                }
            }
        }
        visited[a[i]] = true;
        f += d[a[i - 1]][a[i]];
    }
    f += d[a[n]][a[1]];
    cout << f;
    return 0;
}