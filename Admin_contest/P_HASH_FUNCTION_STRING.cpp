#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
long long int c[N];
long long int computeExponential(int k)
{
    if (k == 0)
        return 1;
    if (c[k] != -1)
        return c[k];
    else
    {
        c[k] = (computeExponential(k - 1) * 256) % m;
        return c[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // input();
    c[0] = 1;
    loop(i, 1, N)
    {
        c[i] = -1;
    }
    string str;
    cin >> n;
    cin >> m;
    // loop(i, 1, 100)
    // {
    //     cout << computeExponential(i) << endl;
    // }
    int sum = 0;
    loop(i, 1, n)
    {
        cin >> str;
        // cout << str << " " << str.size() << endl;
        loop(j, 0, str.size() - 1)
        {
            sum = (sum + (str[j]) * computeExponential(str.size() - 1 - j)) % m;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}