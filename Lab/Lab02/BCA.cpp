#include <bits/stdc++.h>
#define N 50

using namespace std;

int n, m;
vector<int> a[N]; // a[i] la danh sach cac ong thay day mon i
bool c[N][N];
int load[N];
int b[N]; // mon i duoc chia cho thay b[i]
int res = INT_MAX;
int courseUsed = 0;

void checkInput()
{
    cout << m << " " << n << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int e : a[i])
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

void input()
{
    cin >> m >> n;
    int v;
    int v1, v2;
    for (int i = 1; i <= m; i++)
    {
        cin >> v;
        for (int j = 1; j <= v; j++)
        {
            cin >> v1;
            a[v1].push_back(i);
        }
    }
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cin >> v1 >> v2;
        c[v1][v2] = true;
        c[v2][v1] = true;
    }
    // checkInput();
}

bool check(int k, int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == v)
        {
            if (c[i][k] == true)
                return false;
        }
    }
    // cout << "Return true" << endl;
    return true;
}

void solution()
{
    int cmax = 0;
    for (int i = 1; i <= m; i++)
    {
        cmax = max(load[i], cmax);
    }
    res = min(cmax, res);
}

void Try(int k) // chon thay cho mon k
{
    for (int v : a[k])
    {
        if (check(k, v))
        {
            b[k] = v;
            load[v]++;
            if (k == n)
            {
                solution();
            }
            else
            {
                if (load[v] < res)
                    Try(k + 1);
            }
            b[k] = -1;
            load[v]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    for (int i = 0; i < n; i++)
    {
        b[i] = -1; // khoi tao chua giao cho giang vien nao
    }
    input();
    Try(1);
    cout << res << endl;
    return 0;
}