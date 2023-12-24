#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MOD 1000000007
int n;
using namespace std;
int a[N];
void input()
{
    cin >> n;
    int sum = 0;
    int b;
    loop(i, 1, n)
    {
        cin >> b;
        sum += a[b];
        a[b]++;
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}