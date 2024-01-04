#include <bits/stdc++.h>
#define N 10001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m;              // n viec m nguoi
vector<int> tasks[N];  // list staff of tasks
vector<int> staffs[N]; // list task of staffs
int f = 0;
int Fmax = INT_MIN;
bool visitedT[N];
bool visitedS[N];
void input()
{
    cin >> n >> m;
    int k;
    int u;
    loop(i, 1, n)
    {
        cin >> k;
        loop(j, 1, k)
        {
            cin >> u;
            tasks[i].push_back(u);
            staffs[u].push_back(i);
        }
    }
}
bool check(int e, int k)
{
    return !visitedS[e];
}

void solution()
{
    cout << f << endl;
    Fmax = max(Fmax, f);
}
void Try(int k) // gan nguoi cho viec
{
    for (int e : tasks[k])
    {
        if (check(e, k))
        {
            f++;
            visitedT[k] = true;
            visitedS[e] = true;
            if (k == n)
                solution();
            else
            {
                if (Fmax < (f + n - k))
                {
                    Try(k + 1);
                }
            }
            f--;
            visitedT[k] = false;
            visitedS[e] = false;
        }
        else
        {
            if (k == n)
                solution();
            else
            {
                if (Fmax < (f + n - k))
                {
                    Try(k + 1);
                }
            }
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
    Try(1);
    cout << Fmax;
    return 0;
}