#include <bits/stdc++.h>
#define N 50
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n; // paper
int m; // reviewer
int b;
int d[N];                // count number reviewer of each paper
vector<int> l[N];        // vector of reviewer for each paper
vector<int> reviewer[N]; // vector of paper for each reviewer
int c[N][N];
int f[N];
int Fmin = INT_MAX;
bool visited[N][N];
int K[N];
vector<pair<int, int>> pii[N];
pair<int, int> pc[N][N];
void input()
{
    int k;
    int L;
    cin >> n >> m >> b;
    loop(i, 1, n)
    {
        cin >> k;
        K[i] = k;
        loop(j, 1, k)
        {
            cin >> L;
            l[i].push_back(L);
            // reviewer[L].push_back(i);
            pii[i].push_back(make_pair(j - 1, L));
        }
    }
}

void printVector()
{
    loop(i, 1, m)
    {
        cout << f[i] << " ";
    }
    cout << endl;
}
int sumArray()
{
    int sum = 0;
    loop(i, 1, m)
    {
        sum += f[i];
    }
    return sum;
}
// int count_solution = 0;
void solution()
{
    // count_solution++;
    int maxThisSolution = *max_element(f + 1, f + m + 1);
    Fmin = min(Fmin, maxThisSolution);
    if (maxThisSolution == 3)
    {
        printVector();
        loop(i, 1, n)
        {
            loop(j, 1, b)
            {
                cout << pc[i][j].second << " ";
            }
            cout << endl;
        }
    }
}

void TryX(int i, int k) // reviewer number i for paper k
{
    for (int v = pc[k][i - 1].first + 1; v < K[k]; v++)
    {
        pc[k][i] = pii[k][v];
        d[k]++;                // so luong nguoi review paper k
        f[pii[k][v].second]++; // so paper nguoi v review
        if (i == b)
        {
            if (k == n)
            {
                solution();
            }
            else
            {
                if (f[pii[k][v].second] < Fmin)
                    TryX(2, k + 1);
            }
        }
        else
        {
            if (f[pii[k][v].second] < Fmin)
                TryX(i + 1, k);
        }
        d[k]--;
        f[pii[k][v].second]--;
    }
}

void TryY(int k)
{
    for (int i = 0; i < K[k] - b + 1; i++)
    {

        pc[k][1] = pii[k][i];
        d[k]++;                // so luong nguoi review paper k
        f[pii[k][i].second]++; // so paper nguoi v review
        if (k == n)
        {
            if (f[pii[k][i].second] < Fmin)
                TryX(2, 1);
        }
        else
        {
            if (f[pii[k][i].second] < Fmin)
            {
                TryY(k + 1);
            }
        }
        d[k]--;
        f[pii[k][i].second]--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    TryY(1);
    if (Fmin == INT_MAX)
    {
        cout << -1;
    }
    else
        cout << Fmin;
    return 0;
}
