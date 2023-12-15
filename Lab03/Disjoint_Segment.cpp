#include <bits/stdc++.h>
#define N 100001
int n;
std::pair<int, int> pii[N];
using namespace std;
std::pair<int, int> presult[N];

int result = 0;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return (a.second) < (b.second);
}

void checkinput()
{
    for (int i = 0; i < n; i++)
    {
        cout << pii[i].first << " " << pii[i].second << endl;
    }
}

void input()
{
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        pii[i] = (make_pair(a, b));
    }
    sort(pii, pii + n, compare);
    // checkinput();
}

bool check(pair<int, int> first, pair<int, int> second)
{
    // if (first.first > second.second)
    //     swap(first, second);
    return first.second < second.first;
}

bool checkarray(pair<int, int> v)
{
    for (int i = 0; i <= result; i++)
    {
        // cout << presult[i].first << " " << presult[i].second
        //      << " Compare to " << v.first << " " << v.second << endl;
        if (!check(presult[i], v))
            return false;
    }
    return true;
}

void solve()
{
    // cout << "Solving" << endl;
    pair<int, int> v;
    v = pii[0];
    presult[result] = v;
    // result++;

    for (int i = 1; i < n; i++)
    {
        v = pii[i];
        if (checkarray(v))
        {
            result++;
            presult[result] = v;
            // cout << pii[i].first << " " << pii[i].second << endl;
        }
    }
}

void thamlam3()
{
    pair<int, int> first, second;
    first = pii[0];
    result++;

    for (int i = 1; i < n; i++)
    {
        second = pii[i];
        if (check(first, second))
        {
            result++;
            first = second;
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
    // solve();
    // cout << result + 1;
    thamlam3();
    cout << result;
    return 0;
}