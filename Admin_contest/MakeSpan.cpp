#include <bits/stdc++.h>
#define N 10001
#define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int n, m;
int d[N];
vector<int> c[N];
int number_of_constraints[N];
bool completed[N];
deque<pair<int, int>> dq;

vector<pair<int, int>> a;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
void input()
{
    cin >> n >> m;
    int c1, c2;
    loop(i, 1, n)
    {
        cin >> d[i];
    }
    loop(i, 1, m)
    {
        cin >> c1 >> c2;
        c[c1].push_back(c2);
        number_of_constraints[c1]++;
    }
    // loop(i, 1, n)
    // {
    //     cout << i << ": ";
    //     for (int e : c[i])
    //         cout << e << " ";
    //     cout << endl;
    // }
    loop(i, 1, n) a.push_back(make_pair(i, number_of_constraints[i]));
    sort(a.begin(), a.end(), compare);
    for (int i = 0; i < n; i++)
    {
        // cout << a[i].first << " " << a[i].second << endl;
        dq.push_back(a[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();

    pair<int, int> schedule[N];
    pair<int, int> v;
    int f = 0;
    while (!dq.empty())
    {
        v = dq.front();
        dq.pop_front();
        if (v.second == 0)
        {
            schedule[v.first] = make_pair(0, d[v.first]);
            completed[v.first] = true;
            f = max(f, schedule[v.first].second);
        }
        else
        {
            int check = 1;
            int max_end = 0;
            for (int e : c[v.first])
            {
                if (!completed[e])
                {
                    dq.push_back(v);
                    check = 0;
                    break;
                }
                else
                {
                    max_end = max(max_end, schedule[e].second);
                }
            }
            if (check)
            {
                schedule[v.first] = make_pair(max_end, max_end + d[v.first]);
                f = max(f, schedule[v.first].second);
                completed[v.first] = true;
            }
        }
    }
    cout << f;
    return 0;
}