#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    int n;
    int m;
    cin >> n >> m;
    char s[N];
    loop(i, 0, m - 1) s[i] = '0';
    s[m] = '\0';
    // printf("%s\n", s);
    int v;
    loop(i, 1, n)
    {
        // cout << "Run loop" << endl;
        cin >> v;
        int a = v;
        int k = m - 1;
        int digits = 0;
        while (a > 0)
        {
            s[k--] = '0' + a % 10;
            a = a / 10;
            digits++;
        }
        printf("%s\n", s);
        loop(j, 1, digits) s[m - j] = '0';
        // loop(j, 0, m - 1) s[j] = '0';
    }
    return 0;
}