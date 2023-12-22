#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int c[N];
int f[N];
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> c[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    f[1] = c[1];
    loop(i, 2, n)
    {
        f[i] = max(c[i], f[i - 1] + c[i]);
    }
    cout << *max_element(f + 1, f + n + 1);
    return 0;
}