// CPP
// Chua co truy vet
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000 + 100
int n;
int a[MAX];
int s[MAX];
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int maxIncSubSeq()
{
    s[0] = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        s[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                s[i] = max(s[i], s[j] + 1);
            }
            res = max(res, s[i]);
        }
    }
    return res;
}

int main()
{
    input();
    cout << maxIncSubSeq();
    return 0;
}