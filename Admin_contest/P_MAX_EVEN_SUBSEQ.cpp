#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int a[N];
long long int c[N];
long long int l[N];
void input()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
    }
    loop(i, 1, n)
    {
        c[i] = INT_MIN;
        l[i] = INT_MIN;
    }
}

void even(int i)
{
    if (c[i - 1] != INT_MIN && c[i - 1] > 0)
    {
        c[i] = a[i] + c[i - 1];
    }
    else
        c[i] = a[i];
    if (l[i - 1] != INT_MIN)
    {
        l[i] = l[i - 1] + a[i];
    }
}

void odd(int i)
{
    if (c[i - 1] != INT_MIN && c[i - 1] > 0)
    {
        l[i] = c[i - 1] + a[i];
    }
    else
        l[i] = a[i];
    if (l[i - 1] != INT_MIN)
    {
        c[i] = l[i - 1] + a[i];
    }
}

void maxSubSeq()
{
    if (a[1] % 2 == 0)
        c[1] = a[1];
    else
        l[1] = a[1];
    loop(i, 2, n)
    {
        if (a[i] % 2 == 0)
        {
            even(i);
        }
        else
        {
            odd(i);
        }
    }
    // loop(i, 1, n)
    // {
    //     cout << c[i] << "";
    // }
    // cout << endl;
    // loop(i, 1, n)
    // {
    //     cout << l[i] << "";
    // }
    // cout << endl;
    long long int res = *max_element(c + 1, c + n + 1);
    if (res != INT_MIN)
    {
        cout << res;
    }
    else
        cout << "NOT_FOUND";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    maxSubSeq();
    return 0;
}