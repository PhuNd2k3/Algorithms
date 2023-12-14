#include <bits/stdc++.h>
#define N 100
using namespace std;

int n, K, q;
int d[N];
int c[N][N];
int Fmin = INT_MAX;
int f = 0;
int segment = 0; // segment = n+(so xe su dung) => di qua tat ca cac diem va quay ve 0

int x[N];    // diem tiep theo cua khach hang i (tong cong n khach hang)
int y[N];    // diem khoi dau cua xe thu i tu diem 0 (tong cong k xe, co the dung < k xe)
int load[N]; // khoi luong mang theo cua xe i
bool visited[N];

int routeUsed = 0;

void checkinput()
{
    cout << n << endl
         << K << endl
         << q << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void input()
{
    cin >> n >> K >> q;
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

void solution()
{
    Fmin = min(Fmin, f);
}

bool checkX(int i, int k, int v)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (load[k] + d[v] > q)
        return false;
    return true;
}

void TryX(int i, int k) // tim duong tiep theo sai i (a.k.a x[i]), route cua xe k
{
    if (i > 0)
    {
        for (int v = 0; v <= n; v++)
        {
            if (checkX(i, k, v))
            {
                x[i] = v;
                f += c[i][v];
                load[k] += d[v];
                visited[v] = true;
                segment++;
                if (v == 0)
                { // return to the depot
                    if (k < K)
                    {
                        if (f < Fmin)
                            TryX(y[k + 1], k + 1);
                    }
                    else
                    {
                        if (segment == routeUsed + n)
                            solution();
                    }
                }
                else
                {
                    if (Fmin > f)
                        TryX(v, k);
                }

                f -= c[i][v];
                load[k] -= d[v];
                segment--;
                visited[v] = false;
            }
        }
    }
    else if (k < K && f < Fmin)
        TryX(y[k + 1], k + 1);
}

bool checkY(int k, int v)
{
    if (v == 0)
        return true;
    if (visited[v])
        return false;
    if (load[k] + d[v] > q)
        return false;
    return true;
}

void TryY(int k)
{
    for (int v = (y[k - 1] == 0 ? 0 : (y[k - 1] + 1)); v <= n; v++) // vi khoi luong moi xe nhu nhau nen gia su y[1] < y [2] ...
    {
        if (checkY(k, v))
        {
            y[k] = v;
            load[k] += d[v];
            f += c[0][v];
            visited[v] = true;
            if (v > 0)
            {
                segment++;
            }
            if (f < Fmin)
            {
                if (k == K)
                {
                    routeUsed = segment;
                    TryX(y[1], 1);
                }
                else
                {
                    TryY(k + 1);
                }
            }
            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0)
            {
                segment--;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    input();

    y[0] = 0;
    TryY(1);
    cout << Fmin << endl;
    return 0;
}