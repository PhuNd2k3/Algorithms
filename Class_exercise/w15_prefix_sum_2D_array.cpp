#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
int a[N][N];
int s[N][N];
void input()
{
    cin >> n >> m;
    loop(i, 1, n)
    {
        loop(j, 1, m)
        {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    input();
    int k;
    cin >> k;
    int r1, c1, r2, c2;
    loop(i, 1, k)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1] << endl;
    }
    return 0;
}