#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int m;
int a[N];
long long int sum = 0;

// int rmq(int i, int j)
// {
//     if (i == j)
//         return a[i];
//     int mid = (i + j) / 2;
//     return min(rmq(i, mid), rmq(mid + 1, j));
// }

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }
    cin >> m;
    int v1, v2;
    // int fmin = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        // for (int i = v1; i <= v2; i++)
        // {
        //     fmin = min(fmin, a[i]);
        // }
        // sum += fmin;
        // fmin = INT_MAX;
        // sum += rmq(v1, v2);
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