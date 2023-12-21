#include <bits/stdc++.h>
#define N 50
// #define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int Fmin = INT_MAX;
int Fmax = INT_MIN;
int n;
int f[N];
void input()
{
    cin >> n;
}

bool check(int v, int k)
{
    return !(f[k - 1] + v == 2) || k == 1;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << f[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (check(v, k))
        {
            f[k] = v;
            if (k == n)
                solution();
            else
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