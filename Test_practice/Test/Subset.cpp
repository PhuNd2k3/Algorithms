#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int f = 0;
int Fmin = INT_MAX;
int Fmax = INT_MIN;
int n;
int c[N][N];
int visited[N];
int d[N];
int a[N];

void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> d[i];
    }
}

void solution()
{
    int flag = 0;
    loop(i, 1, n)
    {
        if (visited[i])
        {
            flag = 1;
            cout << d[i] << " ";
        }
    }
    if (flag)
        cout << endl;
}

void Try(int k)
{
    for (int v = 1; v >= 0; v--)
    {
        visited[k] = v;
        if (k == n)
        {
            solution();
        }
        else
            Try(k + 1);
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