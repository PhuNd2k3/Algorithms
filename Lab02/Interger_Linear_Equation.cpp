#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int m;
int a[N];
int c[N];
int maxA = 0;
int res = 0;
int sum = 0;
int t[N];
void input()
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // maxA = max(maxA, (int)ceil( (m-n) / a[i]));
        if (i == 1)
        {
            t[i] = a[i];
        }
        else
            t[i] = t[i - 1] + a[i];
    }
}
void printSolution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
void solution()
{
    res++;
    // printSolution();
}

void Try(int k)
{
    // for (int i = 1; i <= maxA; i++)
    for (int i = 1; i <= ((m - sum - (t[n] - t[k]) / a[k])); i++)
    {
        c[k] = i;
        sum += c[k] * a[k];
        if (k == n)
        {
            if (sum == m)
                solution();
        }
        else
        {
            if (sum <= m)
                Try(k + 1);
        }
        sum -= c[k] * a[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    input();
    Try(1);
    cout << res;
    return 0;
}