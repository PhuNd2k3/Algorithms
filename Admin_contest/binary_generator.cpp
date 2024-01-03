#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int f = 0;
int Fmin = INT_MAX;
int Fmax = INT_MIN;
int n;
bool visited[N];
int d[N];

void input()
{
    cin >> n;
}

void solution()
{
    loop(i, 1, n)
    {
        cout << d[i];
    }
    cout << endl;
}

void Try(int k)
{
    loop(v, 0, 1)
    {
        d[k] = v;
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
    // freopen("input.txt", "r", stdin);
    input();
    Try(1);
    return 0;
}