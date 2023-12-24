#include <bits/stdc++.h>
#define N 25
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
vector<int> a;
int year;
int res = 0; // ket qua cua bai toan
int f = 0;   // gia tri tong hien thoi trong vong Try
bool visited[N];
int c[N];
void input()
{
    int tmp;
    cin >> n;
    loop(i, 1, n)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), greater<int>());
    cin >> year;
    // loop(i, 0, n - 1)
    // {
    //     cout << a[i] << " ";
    // }
}

void solution()
{
    // loop(i, 1, n)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    if (f % 5 == 0)
    {
        res++;
    }
}

bool check(int v, int k)
{
    if (visited[v])
        return false;
    if (k == 1)
        return true;
    else
    {
        return a[v] < c[k - 1];
    }
}

void Try(int k)
{
    for (int v = 0; v < n; v++)
    {
        if (check(v, k))
        {
            c[k] = a[v];
            // cout << c[k] << endl;
            f = f + a[v];
            if (f >= year)
            {
                solution();
            }
            if (k < n)
            {
                Try(k + 1);
            }
            f = f - a[v];
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