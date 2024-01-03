#include <bits/stdc++.h>
#define N 5001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;
pair<int, int> Bus[N];
vector<int> a[N];
int f = 0;
int Fmin = INT_MAX;
void input()
{
    cin >> n;
    cin >> m;
    int tmp1;
    int tmp2;
    loop(i, 1, n)
    {
        cin >> tmp1;
        cin >> tmp2;
        Bus[i] = make_pair(tmp1, tmp2);
    }
    loop(i, 1, m)
    {
        cin >> tmp1;
        cin >> tmp2;
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}