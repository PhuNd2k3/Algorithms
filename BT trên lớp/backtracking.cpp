// CPP
#include <bits/stdc++.h>
using namespace std;

// 1<=x<=M-(n-1)
int sum = 0;
int n, M;
int x[100];
bool check_sum(int M)
{
    return sum == M;
}

void solution(int x[])
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; (v <= (M - sum - (n - k - 1))); v++) // M-T-(n-k)
    {
        if (true)
        {
            x[k] = v;
            sum += v;
        }
        if (((k + 1) == n))
        {
            if (check_sum(M))
                solution(x);
        }
        else
            Try(k + 1);
        sum -= v;
    }
}

int main()
{
    cin >> n;
    cin >> M;
    Try(0);
    return 0;
}