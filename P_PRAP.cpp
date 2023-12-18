#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m, b;
int d[N]; // count number reviewer each paper
vector<int> l[N];
int Fmin = INT_MAX;
int f = 0;
void input()
{
    int k;
    int L;
    cin >> n >> m >> b;
    loop(i, 1, n)
    {
        cin >> k;
        loop(j, 1, k)
        {
            cin >> L;
            l[i].push_back(L);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();

    if (Fmin != INT_MAX)
    {
        cout << -1;
    }
    else
        cout << Fmin;
    return 0;
}