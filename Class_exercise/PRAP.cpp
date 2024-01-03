#include <bits/stdc++.h>
#define MAX_N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int f = 0;
int Fmin = INT_MAX;
int n;
int c[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int N, M, b;
int loadR[MAX_N];

vector<int> L[MAX_N]; // L[i] list reviewer of paper i

void input()
{
    cin >> N >> M >> b;
    int k;
    int list_element;
    loop(i, 1, N)
    {
        cin >> k;
        loop(j, 1, k)
        {
            cin >> list_element;
            L[i].push_back(list_element);
        }
    }
}
bool check(int v, int k)
{
    return !visited[k][v];
}
void printSolution()
{
    loop(i, 1, N)
    {
        loop(j, 1, b)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
void solution()
{
    // printSolution();
    // cout << endl;
    Fmin = min(Fmin, *max_element(loadR + 1, loadR + M + 1));
}

void Try(int k, int l)
{
    for (int v : L[k])
    {
        if (check(v, k))
        {
            visited[k][v] = true;
            loadR[v]++;
            // c[k][l] = v;
            if (k == N && l == b)
            {
                solution();
            }
            else
            {
                if (loadR[v] < Fmin)
                {
                    if (l == b)
                    {
                        Try(k + 1, 1);
                    }
                    else
                        Try(k, l + 1);
                }
            }
            visited[k][v] = false;
            loadR[v]--;
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
    Try(1, 1);
    cout << ((Fmin != INT_MAX) ? Fmin : -1);
    return 0;
}