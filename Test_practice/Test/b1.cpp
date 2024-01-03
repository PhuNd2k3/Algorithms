#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MOD 1000000007
int n;
using namespace std;
int a[N]; // luu de bai
int b[N]; // b[i]  la so lan so i xuat hien trong day
int res = 0;
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
        res = (res + b[a[i] - 1] + b[a[i] + 1]) % MOD;
        b[a[i]]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    cout << res % MOD;
    return 0;
}