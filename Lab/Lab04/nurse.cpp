#include <bits/stdc++.h>
#define N 1000001

using namespace std;
int f = 0;
int n;
int l1, l2;

int rest[N];
int lastday[N];
void input()
{
    cin >> n >> l1 >> l2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();

    rest[1] = 1;
    lastday[1] = 0;
    for (int i = 2; i < l1; i++)
    {
        lastday[i] = 0;
        rest[i] = 0;
    }
    // xep cho tu l1 -> l2
    for (int i = l1; i <= l2; i++)
    {
        rest[i] = lastday[i - 1];
        lastday[i] = 1;
        for (int j = i - l2 > 1 ? i - l2 : 1; j <= i - l1; j++)
        {
            lastday[i] += rest[j];
        }
    }

    for (int i = l2 + 1; i <= n; i++)
    {
        rest[i] = lastday[i - 1];
        lastday[i] = 0;
        for (int j = i - l2; j <= i - l1; j++)
        {
            lastday[i] += rest[j];
        }
    }

    /////
    cout << lastday[n] + rest[n]
         << endl;
    // cout << "         ";
    // for (int i = 1; i <= n; i++)
    //     cout << i << " ";
    // cout << "\nRest:    ";
    // for (int i = 1; i <= n; i++)
    //     cout << rest[i] << " ";
    // cout << "\nlastday: ";
    // for (int i = 1; i <= n; i++)
    //     cout << lastday[i] << " ";

    return 0;
}