#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
int d[N][N];
int visited[N];
void input()
{
    cin >> n;

    int dmin = INT_MAX;
    int indexDmin;
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            cin >> d[i][j];
            if (dmin > d[i][j])
            {
                dmin = d[i][j];
                indexDmin = i;
            }
        }
    }
    cout << n << endl;
    // cout << indexDmin << endl;
    int count = 0;
    int i = indexDmin;
    int index;
    int Fmin = INT_MAX;
    while (1)
    {
        cout << i << " ";
        visited[i] = true;
        count++;
        // cout << "count: " << count << " i: " << i << endl;

        if (count == n)
            break;
        loop(j, 1, n)
        {
            if (!visited[j])
            {
                if (i != j)
                {
                    // cout << i << " " << j << endl;
                    if (Fmin > d[i][j])
                    {
                        Fmin = d[i][j];
                        index = j;
                    }
                    // cout << "index: " << index << endl;
                }
            }
        }
        Fmin = INT_MAX;
        i = index;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}