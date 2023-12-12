#include <bits/stdc++.h>
#define N 1000

using namespace std;

int n;
int a[N];
int f = 0;

void input()
{
    cin >> n;
}

void solution()
{
    f += 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}

bool check1(int v, int k)
{
    if (k == 1)
        return true;
    if (a[k - 1] == 1)
        return a[k] != 1;
    if (a[k - 1] == 0)
        return a[k] != 0;
    return true;
}

bool check(int v, int k)
{
    // cout << "v: " << v << " k: " << k << endl;
    // cout << a[k] << " - " << a[k - 1] << endl;
    // cout << " check: " << check1(v, k) << endl;
    if (k == 1)
        return true;
    if (a[k - 1] == 1 && v == 1)
        return false;
    if (a[k - 1] == 0 && v == 0)
        return false;
    return true;
}

void Try(int k)
{
    for (int v = 0; v <= 2; v++)
    {
        if (check(v, k))
        {
            a[k] = v;
            if (k == n)
            {
                solution();
            }
            else
                Try(k + 1);
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << f;
    return 0;
}
