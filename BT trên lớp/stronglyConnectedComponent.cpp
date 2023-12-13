#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n;
int m;
vector<int> a[N];
vector<int> ar[N];

bool visited[N];

int nbCC = 0;
int cc[N];

void input()
{
    int v1, v2;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v1;
        cin >> v2;
        a[v1].push_back(v2);
        ar[v2].push_back(v1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    input();
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    // TO do
    cout << count;
    return 0;
}