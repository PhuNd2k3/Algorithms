#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, k;
int w[N];
int l[N];
int W[N];
int L[N];
int c[N];
int t[N], x[N], y[N], o[N];
vector<int> truck;
int loaded = 0;
struct cmp
{
    bool operator()(int a, int b)
    {
        return c[a] > c[b];
    }
};
priority_queue<int, vector<int>, cmp> pq;
vector<int> items;
bool compare(int a, int b)
{
    return l[a] * w[a] < l[b] * w[b];
}
void input()
{
    cin >> n >> k;
    loop(i, 1, n)
    {
        items.push_back(i);
        cin >> w[i] >> l[i];
    }
    loop(i, 1, k)
    {
        cin >> W[i] >> L[i] >> c[i];
    }
    loop(i, 1, k)
    {
        pq.push(i);
    }
    sort(items.begin(), items.end(), compare);
}
void load(int v)
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    while (!pq.empty() && loaded < n)
    {
        load(pq.top());
        pq.pop();
    }
    return 0;
}