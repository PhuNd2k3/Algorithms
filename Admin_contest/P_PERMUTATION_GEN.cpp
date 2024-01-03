#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
void input()
{
    cin >> n;
}
bool visited[N];
int c[N];
void solution()
{
    loop(i, 1, n)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
void Try(int k)
{
    loop(v, 1, n)
    {
        if (!visited[v])
        {
            visited[v] = true;
            c[k] = v;
            if (k == n)
            {
                solution();
            }
            else
                Try(k + 1);
            visited[v] = false;
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