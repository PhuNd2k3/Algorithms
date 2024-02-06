#include <bits/stdc++.h>
#define N 2001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int a[N];
int n;
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    sort(a + 1, a + n + 1);
    int res = 0;
    loop(k, 3, n)
    {
        int i = 1;
        int j = k - 1;
        while (j > i)
        {
            if (a[i] + a[j] == a[k])
            {
                res++;
                i++;
                j--;
            }
            else if (a[i] + a[j] > a[k])
                j--;
            else
                i++;
        }
    }
    cout << res << endl;
    return 0;
}