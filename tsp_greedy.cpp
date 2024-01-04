#include <bits/stdc++.h>
using namespace std;
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
int n;
int tsp[N][N];
int come[N]; // da co thanh pho nao di den i chua
int go[N];   // tu i da di den thanh pho nao chua
int nextCity[N];
int visited[N];
vector<pair<int, int>> city;
queue<pair<int, int>> q;
void findMinRoute()
{
    memset(come, 0, sizeof(come));
    memset(go, 0, sizeof(go));
    // int count = 0;
    pair<int, int> v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (!go[v.first] && !come[v.second])
        {
            // if (nextCity[v.second] == v.first)
            //     continue;
            nextCity[v.first] = v.second;
            go[v.first] = 1;
            come[v.second] = 1;
            // cout << "Add: " << v.first << " " << v.second << endl;
        }
    }
    int start = 1;
    int x = 1;
    int y = 0;
    int Fmin = INT_MAX;
    int indexMin;
    int mark[N];
    while (1)
    {
        y++;
        mark[y] = x;
        cout << x << " ";
        visited[x] = 1;
        if (y == n)
            break;
        if (nextCity[x] == start || nextCity[x] == 0)
        {
            loop(i, 1, n)
            {
                if (!visited[i])
                {
                    if (tsp[x][i] < Fmin)
                    {
                        Fmin = tsp[x][i];
                        indexMin = i;
                    }
                }
            }
            // cout << "\nBreak: " << start << " " << x << " " << indexMin << endl;
            nextCity[x] = indexMin;
            x = indexMin;
            start = indexMin;
            Fmin = INT_MAX;
        }
        else
            x = nextCity[x];
    }
    // int sum = 0;
    // loop(i, 1, n - 1)
    // {
    //     sum += tsp[mark[i]][mark[i + 1]];
    // }
    // sum += tsp[mark[n]][mark[1]];
    // cout << "Sum: " << sum << endl;
}
bool compare(pair<int, int> a, pair<int, int> b)
{
    return tsp[a.first][a.second] < tsp[b.first][b.second];
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    cout << n << "\n";
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> tsp[i][j];
            if (tsp[i][j] == 0)
                tsp[i][j] = INT_MAX;
            if (i != j)
                city.push_back(make_pair(i, j));
        }
    }
    sort(city.begin(), city.end(), compare);
    // cout << city.size() << "\n";
    loop(i, 0, n * (n - 1) - 1)
    {
        q.push(city[i]);
    }

    findMinRoute();
}
