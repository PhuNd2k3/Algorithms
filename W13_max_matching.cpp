#include <bits/stdc++.h>
#define N 10001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, m; // n viec m nguoi
int f = 0;
int Fmax = INT_MIN;

/*
    Tasks               Staff

*/
int match[N];         // match[i] = j tuc la task j match voi staff i -> tra ve task
int rMatch[N];        // staff j match voi task i -> tra ve staff
vector<int> tasks[N]; // danh sach dinh (staff) ke voi task
int p[N];             // p[i] la dinh cha (task) cua dinh i (staff) trong qua trinh duyet bfs

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
        }
    }
}

int bfs(int u)
{
    queue<int> q;
    for (int e : tasks[u])
    {
        q.push(e);
        p[e] = u;
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        int mv = match[v];
        if (mv == 0)
            return v;
        for (int x : tasks[mv])
        {
            if (x != rMatch[mv])
            {
                q.push(x);
                p[x] = mv;
            }
        }
    }
    return -1;
}
void increaseMatching(int s, int t)
{
    int x = t;
    while (p[x] != s)
    {
        int px = p[x];
        int nx = rMatch[px];
        match[x] = px;
        rMatch[px] = x;
        x = nx;
    }
    match[x] = p[x];
    rMatch[p[x]] = x;
}

void maxMatching()
{
    int maxCount = 0;
    loop(i, 1, n)
    {
        int t = bfs(i);
        if (t != -1)
        {
            increaseMatching(i, t);
            maxCount++;
            cout << maxCount << endl;
        }
        else
        {
            break;
        }
    }
    cout << maxCount << endl;
    cout << "End";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    maxMatching();
    return 0;
}