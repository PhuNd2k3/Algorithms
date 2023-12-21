#include <bits/stdc++.h>
#define N 51
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MOD 1000000007
using namespace std;
int n;
int sum = 0;
int f = 0;
int c[N];
void input()
{
    cin >> n;
}

void Try(int k)
{
    for (int i = k == 1 ? 1 : c[k - 1]; i <= n; i++)
    {
        sum += i;
        // cout << "Sum: " << sum << endl;
        c[k] = i;
        if (sum == n)
        {
            f++;
            // loop(j, 1, k)
            // {
            //     cout << c[j] << " ";
            // }
            // cout << endl;
        }
        else
        {
            if (sum > n)
            {
                sum -= i;
                break;
            }
            else
                Try(k + 1);
        }
        sum -= i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    input();
    Try(1);
    cout << f;
    return 0;
}