#include <bits/stdc++.h>
#define N 1000001
#define MOD 1000000007
using namespace std;

int n;
int a[N];

int c[N];
int l[N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = 0;
        l[i] = 0;
    }
}

void even(int i)
{
    if (c[i - 1] != 0)
    {
        c[i] = c[i - 1] + 1;
    }
    else
        c[i] = 1;

    if (l[i - 1] != 0)
    {
        l[i] = l[i - 1];
    }
}

void odd(int i)
{
    if (c[i - 1] != 0)
    {
        l[i] = c[i - 1] + 1;
    }
    else
        l[i] = 1;
    if (l[i - 1] != 0)
    {
        c[i] = l[i - 1];
    }
}

void printlist()
{
    cout << "Day chan" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << "\n"
         << "Day le" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
    cout << "\n";
}
void subSeq()
{
    if (a[0] % 2 == 0)
    {
        c[0] = 1;
    }
    else
        l[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] % 2 == 0)
            even(i);
        else
            odd(i);
        printlist();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    subSeq();
    cout << accumulate(c, c + n, 0) << endl;
    cout << accumulate(l, l + n, 0);
    return 0;
}