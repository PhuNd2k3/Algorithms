#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
int a[N];
vector<int> b;
// pair<int, int> c[N];
void input()
{
    cin >> n >> m;
    loop(i, 1, n)
    {
        cin >> a[i];
        b.push_back(a[i]);
        // c[a[i]] = make_pair(i, 1);
    }
    sort(b.begin(), b.end());
}

int merge(int l, int mid, int r)
{
    int count = 0;
    loop(i, l, mid)
    {
        loop(j, mid + 1, r)
        {
            if (a[i] + a[j] == m)
                count++;
        }
    }
    return count;
}

int countSum(int l, int r)
{
    if ((l >= r))
        return 0;
    if (l == r - 1)
        if (a[l] + a[r] == m)
            return 1;
    int mid = (l + r) / 2;
    return countSum(l, mid) + countSum(mid + 1, r) + merge(l, mid, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    // int f = 0;
    // loop(i, 1, n - 1)
    // {
    //     loop(j, i + 1, n)
    //     {
    //         if (a[i] + a[j] == m)
    //             f++;
    //     }
    // }
    // cout << f;

    // int l = 1;
    // int r = n;
    // cout << countSum(l, r);
    // int f = 0;
    // loop(i, 1, n)
    // {
    //     if (c[m - a[i]].first < i)
    //         f += c[m - a[i]].second;
    // }

    int f = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (b[j] > m)
        {
            j--;
            continue;
        }
        if (b[i] + b[j] < m)
        {
            i++;
            continue;
        }
        if (b[i] + b[j] > m)
        {
            j--;
            continue;
        }
        f++;
        i++;
        j--;
    }
    cout << f;
    return 0;
}