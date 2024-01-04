#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
int a[N];
int s[N];
void input()
{
    cin >> n;
    a[0] = 0;
    s[0] = 0;
    int v;
    cin >> v;
    a[1] = v;
    s[1] = v;
    loop(i, 2, n)
    {
        cin >> v;
        a[i] = v;
        s[i] = v + s[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    input();
    cin >> m;
    int i, j;
    loop(k, 1, m)
    {
        cin >> i;
        cin >> j;
        cout << s[j] - s[i - 1] << endl;
    }
    return 0;
}