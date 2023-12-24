#include <bits/stdc++.h>
#define N 20
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
vector<int> a;
int m;
int visited[N];
int c[N];
int res = 0;
int sum = 0;
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> m;
        a.push_back(m);
    }
    cin >> m;
    sort(a.begin(), a.end(), greater<int>());
    // loop(i, 0, n - 1)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}
int check(int v, int k)
{
    if (visited[v])
        return 0;
    if (k == 1)
        return 1;
    else
        return a[v] < c[k - 1];
}
void solution(int v, int k)
{
    res += pow(2, n - v - 1);
    // loop(i, 1, k)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    // cout << "res = " << res << endl;
}
void Try(int k)
{
    for (int v = 0; v < n; v++)
    {
        if (check(v, k))
        {
            c[k] = a[v];
            sum += a[v];
            visited[v] = 1;
            if (sum >= m)
                solution(v, k);
            else
                Try(k + 1);
            sum -= a[v];
            visited[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    input();
    Try(1);
    // cout << n << " " << m << endl;
    cout << res;
    return 0;
}