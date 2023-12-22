#include <bits/stdc++.h>
#define N 100001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
vector<int> job[N];
bool compare(int a, int b)
{
    return a > b;
}
int numberOfVector = 0;
int maxD = 0;
bool visited[N];
void input()
{
    cin >> n;
    int d, p;
    loop(i, 1, n)
    {
        cin >> d;
        cin >> p;
        maxD = max(maxD, d);
        if (d == 0)
            continue;
        job[d].push_back(p);
        if (!visited[d])
        {
            visited[d] = true;
            numberOfVector++;
        }
    }
    loop(i, 1, maxD - 1)
    {
    }
    loop(i, 1, maxD)
    {
        if (!job[i].empty())
        {
            sort(job[i].begin(), job[i].end(), compare);
        }
    }
}
int profit = 0;
int greedy()
{
    // int index;
    // int maxProfit = 0;
    // int secondMax = 0;
    // profit[maxD] = job[maxD][0];
    // job[maxD].erase(job[maxD].begin());
    // int secondIndex;
    // if (!job[maxD].empty())
    // {
    //     maxProfit = job[maxD][0];
    //     index = maxD;
    // }
    // if (job[maxD].size() == 2)
    // {
    //     secondMax = job[maxD][1];
    //     secondIndex = maxD;
    // }
    priority_queue<int> pq;
    for (int i = maxD; i > 0; i--)
    {
        for (auto it = job[i].begin(); it != job[i].end(); it++)
        {
            pq.push(*it);
        }
        if (!empty(pq))
        {
            profit += pq.top();
            pq.pop();
        }
    }
    return profit;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    input();
    cout << greedy();
    return 0;
}