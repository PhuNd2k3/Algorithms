#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int f = 0;
int res = 0;
int n;
int d[N];
int a[N];
int m;
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
    }
    cin >> m;
}
bool check(int v, int k)
{
    if (k == 1)
    {
        // cout << (k == 1) << endl;
        return true;
    }
    // cout << (a[v] > d[k - 1]) << endl;
    return a[v] >= d[k - 1];
}
void solution(int k)
{
    // loop(i, 1, k)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    res++;
}
void Try(int k)
{
    loop(i, 1, n)
    {
        if (check(i, k))
        {
            f += a[i];
            d[k] = a[i];
            if (f == m)
            {
                solution(k);
            }
            else
            {
                if (f < m)
                {
                    Try(k + 1);
                }
            }
            f -= a[i];
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
    cout << res;
    return 0;
}