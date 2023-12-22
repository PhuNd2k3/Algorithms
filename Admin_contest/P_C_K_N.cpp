#include <bits/stdc++.h>
#define N_MAX 10000
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MOD 1000000007
using namespace std;
int N;
int K;
long long int f = 0;
long long int C[N_MAX][N_MAX];
void input()
{
    cin >> K;
    cin >> N;
    loop(i, 0, K)
    {
        loop(j, 0, N)
        {
            C[i][j] = -1;
        }
    }
    // cout << "N: " << N << " K: " << K << endl;
}

long long int c(int k, int n)
{
    if (C[k][n] == -1)
    {
        if (k > n)
        {
            C[k][n] = 0;
            return C[k][n];
        }
        if (k == n)
        {
            C[k][n] = 1;
            return C[k][n];
        }
        if (k == 0)
        {
            C[k][n] = 1;
            return C[k][n];
        }
        if (n == 0)
        {
            C[k][n] = 1;
            return C[k][n];
        }
        C[k][n] = (c(k, n - 1) % MOD + c(k - 1, n - 1) % MOD);
        // cout << "C " << k << " " << n << ": " << C[k][n] << endl;
    }
    return C[k][n] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    cout << c(K, N);
    return 0;
}