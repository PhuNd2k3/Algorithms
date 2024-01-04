// CPP
#include <bits/stdc++.h>
using namespace std;

#define N 100;
int matrix[20][20];
bool visited[20];
int f_min = std::numeric_limits<int>::max();
int c_min = std::numeric_limits<int>::max();
int f = 0;
int n;
int x[20];
bool check(int v, int k)
{
    return (visited[v] == false);
}

void solution()
{
    cout << f_min << endl;
}

void Try(int k)
{
    for (int v = 1; v < n; v++)
    {
        if (check(v, k))
        {
            visited[v] = true;
            x[k] = v;
            f = f + matrix[x[k - 1]][x[k]];
            if (k == (n - 1))
            {
                f_min = f_min > (f + matrix[x[k]][x[0]]) ? (f + matrix[x[k]][x[0]]) : f_min;
            }
            else if ((f + c_min * (n - 1 - k + 1)) < f_min)
            {

                Try(k + 1);
            }
            f = f - matrix[x[k - 1]][x[k]];
            visited[v] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            c_min = c_min > matrix[i][j] ? matrix[i][j] : c_min;
        }
    }
    x[0] = 0;
    visited[0] = true;

    Try(1);
    solution();

    return 0;
}