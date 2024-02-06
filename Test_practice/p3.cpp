#include <bits/stdc++.h>
#define N 21
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int sum = 0;
int a[N];
int n;
int bag[N];
int f[3];
int Fmin = INT_MAX;
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    // loop(i, 1, n) cout << a[i] << " ";
}
bool check(int v, int k)
{
    return true;
}
void solution()
{
    Fmin = min(Fmin, 2 * f[1] - sum);
}
void solution2()
{
    Fmin = min(Fmin, 2 * f[2] - sum);
}
void Try(int k)
{
    for (int i = 1; i <= 2; i++)
    {
        bag[k] = i;
        f[i] += a[k];
        if (f[1] > sum / 2)
        {
            solution();
        }
        else if (f[2] > sum / 2)
        {
            solution2();
        }
        else
        {
            if (k < n)
                Try(k + 1);
        }
        f[i] -= a[k];
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
    cout << Fmin;
    return 0;
}