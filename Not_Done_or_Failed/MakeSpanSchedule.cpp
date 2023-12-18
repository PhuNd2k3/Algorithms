#include <bits/stdc++.h>
#define N 10001
#define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
int f = 0;
int Fmin = INT_MAX;

int n, m;
int d[N];
vector<int> c[N];
int res[N];
bool complete[N];
int dmin = INT_MAX;
bool have_constraints[N];
void input()
{
    cin >> n >> m;
    int c1, c2;
    loop(i, 1, n)
    {
        cin >> d[i];
        dmin = min(d[i], dmin);
    }
    loop(i, 1, m)
    {
        cin >> c1 >> c2;
        c[c1].push_back(c2);
        have_constraints[c1] = true;
    }
    loop(i, 1, n)
    {
        cout << i << ": ";
        for (int e : c[i])
            cout << e << " ";
        cout << endl;
    }
}

bool check(int v, int k)
{
    if (complete[v])
        return false;
    for (int e : c[v])
    {
        if (!complete[e])
            return false;
    }
    // loop(i, 0, n - 1)
    // {
    //     if (!complete[i])
    //     {
    //         for (int e : c[i])
    //         {
    //             if (e == v)
    //                 return false;
    //         }
    //     }
    // }
    return true;
}
void printArray(int arr[], int size)
{
    loop(i, 1, size) cout << arr[i] << " ";
    cout << endl;
}
pair<int, int> schedule[N];

void solution()
{
    schedule[res[1]] = make_pair(0, d[res[1]]);
    loop(i, 2, n)
    {
        if (!have_constraints[res[i]])
        {
            schedule[res[i]] = make_pair(0, d[res[i]]);
        }
        else
        {
            int max_end = 0;
            for (int j = i - 1; j >= 1; j--)
            {
                auto it = find(c[res[i]].begin(), c[res[i]].end(), res[j]);
                if (it != c[res[i]].end())
                {
                    max_end = max(max_end, schedule[res[j]].second);
                }
            }
            schedule[res[i]] = make_pair(max_end, max_end + d[res[i]]);
        }
        if (schedule[res[i]].second > Fmin)
            return;
    }
    f = schedule[res[n]].second;
    Fmin = min(f, Fmin);
    if (f == 14)
        printArray(res, n);
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            res[k] = v;
            // printArray(res, k);
            f += d[v];
            complete[v] = true;
            if (k == n)
                solution();
            else
            {
                // if (f /*+ dmin * (n - k)*/ < Fmin)
                // {
                Try(k + 1);
                // }
            }
            f -= d[v];
            complete[v] = false;
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
    loop(i, 1, n) complete[i] = false;
    Try(1);
    cout << Fmin;
    return 0;
}