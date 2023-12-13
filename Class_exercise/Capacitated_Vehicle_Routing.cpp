#include <bits/stdc++.h>
using namespace std;
#define N 100
int n, K, Q;
int d[N];
int c[N][N];

// solution model
int Y[N];
int X[N];
int load[N];
int segment;
int f;
int f_min;
bool visited[N];

void solution()
{
    if (f < f_min)
    {
        f_min = f;
    }
}

void input()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
}

bool checkY(int v, int k)
{
    if (visited[v])
        return false;
    if ((load[k] + d[v]) > Q)
        return false;
    return true;
}

bool checkX(int v, int i, int k)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if ((load[k] + d[v]) > Q)
        return false;
    return true;
}

void TryX(int i, int k)
{
    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, i, k))
        {
            X[i] = v;
            visited[v] = true;
            f += c[i][X[i]];
            load[k] += d[v];
            segment++;
            if (v == 0)
            {
                if (k < K)
                    TryX(Y[k + 1], k + 1);
                else
                {
                    if (segment == (n + K))
                        solution();
                }
            }
            else
            {
                TryX(v, k);
            }
            visited[v] = false;
            f -= c[i][v];
            load[k] -= d[v];
            segment--;
        }
    }
}

void TryY(int k)
{
    for (int v = Y[k - 1] + 1; v <= n - K + k; v++) // why +1
    {
        if (checkY(v, k))
        {
            Y[k] = v;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];
            segment++;
            if (k == K)
            {
                TryX(Y[1], 1);
            }
            else
                TryY(k + 1);
            visited[v] = false;
            f -= c[0][v];
            load[k] -= d[v];
            segment--;
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
    for (int v = 1; v <= n; v++)
        visited[v] = false;
    for (int k = 1; k <= K; k++)
        load[k] = 0;
    f = 0;
    f_min = 1e9;
    Y[0] = 0;
    segment = 0;
    TryY(1);
    cout << f_min << endl;
    return 0;
}