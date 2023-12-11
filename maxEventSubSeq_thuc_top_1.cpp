#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

long long int sc[N];
long long int sl[N];
int a[N];
int n;
long long int ans = INT_MIN;

void input()
{
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Unable to open the input file." << endl;
        exit(1);
    }
    inputFile >> n;
    for (int i = 0; i < n; ++i)
    {
        inputFile >> a[i];
    }
    inputFile.close();
}

void even(long long int i)
{
    // Chan
    if (sc[i - 1] != INT_MIN && sc[i - 1] > 0)
        sc[i] = sc[i - 1] + a[i];
    else
        sc[i] = a[i];

    if (sl[i - 1] != INT_MIN)
        sl[i] = sl[i - 1] + a[i];
    else
        sl[i] = INT_MIN;
}

void odd(long long int i)
{
    // Le
    if (sl[i - 1] != INT_MIN)
        sc[i] = sl[i - 1] + a[i];
    else
        sc[i] = INT_MIN;

    if (sc[i - 1] != INT_MIN && sc[i - 1] > 0)
        sl[i] = sc[i - 1] + a[i];
    else
        sl[i] = a[i];
}
int main()
{
    input();
    loop(i, 0, n - 1) sc[i] = sl[i] = INT_MIN;

    loop(i, 1, n - 1)
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
    loop(i, 1, n) if (sc[i] > ans) ans = sc[i];
    cout << ans << endl;
    return 0;
}
