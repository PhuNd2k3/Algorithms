#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n;
int tsp[N][N];
int visited[N];
vector<pair<int, int>> listCity[N];
int indexMin;
int Fmin;
int k, q;

void findMin(int v)
{
    Fmin = INT_MAX;
    loop(i, 1, n)
    {
        if (i == v || visited[i])
            continue;
        if (tsp[i][v] < Fmin)
        {
            Fmin = tsp[i][v];
            indexMin = i;
        }
    }
}
void findMin2(int v)
{
    Fmin = INT_MAX;
    loop(i, 1, n)
    {
        if (i == v || visited[i])
            continue;
        if (tsp[v][i] < Fmin)
        {
            Fmin = tsp[v][i];
            indexMin = i;
        }
    }
}
void findMinRoute()
{
    int count = 0;
    deque<int> dq;
    dq.push_front(k);
    dq.push_back(q);
    visited[k] = 1;
    visited[q] = 1;
    count = 2;
    int i1, i2;
    int m1, m2;
    while (count != n)
    {
        findMin(dq.front());
        i1 = indexMin;
        m1 = Fmin;
        findMin2(dq.back());
        i2 = indexMin;
        m2 = Fmin;
        if (m1 < m2)
        {
            visited[i1] = 1;
            dq.push_front(i1);
        }
        else
        {
            visited[i2] = 1;
            dq.push_back(i2);
        }
        count++;
    }
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    cout << n << "\n";
    int dMin = INT_MAX;
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> tsp[i][j];
            if (tsp[i][j] != 0 && tsp[i][j] < dMin)
            {
                dMin = tsp[i][j];
                k = i;
                q = j;
            }
        }
    }
    findMinRoute();
}
