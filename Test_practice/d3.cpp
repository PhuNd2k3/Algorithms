#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n;
int m;
using namespace std;
int a[N][N];
int Fmin = INT_MAX;
int f = 0;
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
bool check(int v, int k)
{

    return true;
}

void solution()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}