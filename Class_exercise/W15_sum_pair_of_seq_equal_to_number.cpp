#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
int a[N];
vector<int> c;
void input()
{
    cin >> n;
    cin >> m;
    int v;

    loop(i, 1, n)
    {
        cin >> v;
        a[i] = v;
        c.push_back(v);
    }
    sort(c.begin(), c.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    int f = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (c[j] >= m)
        {
            j--;
            continue;
        }
        if (c[i] + c[j] > m)
        {
            j--;
            continue;
        }
        if (c[i] + c[j] < m)
        {
            i++;
            continue;
        }
        f++;
        i++;
        j--;
    }
    cout << f << endl;
    return 0;
}