#include <bits/stdc++.h>
#define N 51
#define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int n;
int sum = 0;
int c[N];
int K;
void input()
{
    cin >> K;
    cin >> n;
}

void Try(int k)
{
    for (int i = k == 1 ? 1 : c[k - 1]; i <= n; i++)
    {
        sum += i;
        // cout << "Sum: " << sum << endl;
        c[k] = i;
        if (k == K)
        {
            if (sum == n)
            {
                loop(j, 1, k)
                {
                    cout << c[j] << " ";
                }
                cout << endl;
            }
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
    freopen("input.txt", "r", stdin);
    input();
    Try(1);
    return 0;
}