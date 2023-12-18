#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int m, n;
int res[N];
void input()
{
    cin >> n;
    cin >> m;
}

bool check(int v, int k)
{
    return true;
}

void solution()
{
    loop(i, 1, n)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = k == 1 ? 1 : res[k - 1] + 1; v <= m; v++)
    {
        res[k] = v;
        if (k == n)
        {
            solution();
        }
        else
        {
            Try(k + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    Try(1);
    return 0;
}