#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, Q;
int a[N];
// long long int s[N];
void input()
{
    cin >> n >> Q;
    int v;
    loop(i, 1, n)
    {
        cin >> v;
        a[i] = v;
        // s[i] = s[i - 1] + v;
    }
}
// long long int countSum(int start, int end)
// {
//     return s[end] - s[start - 1];
// }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    int res;
    long long int sum;
    if (a[1] <= Q)
        res = 1;
    sum = a[1];
    int i = 1;
    loop(j, 2, n)
    {
        sum += a[j];
        while (sum > Q)
        {
            sum -= a[i];
            i++;
        }
        res = max(res, j - i + 1);
    }
    cout << ((res == 0) ? -1 : res);
    return 0;
}