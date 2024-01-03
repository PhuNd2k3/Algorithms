#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define MOD 1000000007
using namespace std;
int n;
int c[N];
void input()
{
    cin >> n;
}
int sum = 0;
int res = 0;
void solution()
{
    res++;
}
void Try(int k)
{
    loop(v, k == 1 ? 1 : c[k - 1], n)
    {
        c[k] = v;
        sum += v;
        if (sum == n)
        {
            solution();
        }
        else if (sum > n)
        {
            sum -= v;
            break;
        }
        else
            Try(k + 1);
        sum -= v;
    }
}
int a[N][N];
bool mark[N][N];
int representation(int k, int v) // tinh tong = k sao cho moi phan tu khong lon hon n
{
    // luu y k < 0 hoac v < 0 thi bo qua k set a[k][v] va mark[k][v]
    if (!mark[k][v])
    {
        // cout << "k: " << k << " v: " << v << endl;
        if (k > 0 && v > 0)
            mark[k][v] = true;
        if (k == 0)
        {
            a[k][v] = 1;
            return 1;
        }
        if (v == 0)
        {
            // cout << "v = 0" << endl;
            // cout << k << endl;
            // cout << "Return 0" << endl;
            return 0;
        }
        if (k < 0)
        {
            return 0;
        }
        a[k][v] = (representation(k - v, v <= k - v ? v : k - v) + representation(k, v - 1 <= k ? v - 1 : k));
    }

    return a[k][v] % MOD;
}

int countWays(int n)
{
    // table[i] will be storing the number of
    // solutions for value i. We need n+1 rows
    // as the table is constructed in bottom up
    // manner using the base case (n = 0)
    int table[n + 1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all integer one by one and update the
    // table[] values after the index greater
    // than or equal to n

    // neu de la i< n thi se dem so cach trong do + boi it nhat 2 so
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            table[j] = (table[j] + table[j - i]) % MOD;
        }
    }

    return table[n] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    // Try(1);
    // cout << representation(n, n) % MOD;
    cout << countWays(n) % MOD;
    return 0;
}
// // Recursive C++ program for
// // coin change problem.
// #include <bits/stdc++.h>
// using namespace std;

// // Returns the count of ways we can
// // sum coins[0...n-1] coins to get sum "sum"
// int count(int coins[], int n, int sum)
// {

// 	// If sum is 0 then there is 1 solution
// 	// (do not include any coin)
// 	if (sum == 0)
// 		return 1;

// 	// If sum is less than 0 then no
// 	// solution exists
// 	if (sum < 0)
// 		return 0;

// 	// If there are no coins and sum
// 	// is greater than 0, then no
// 	// solution exist
// 	if (n <= 0)
// 		return 0;

// 	// count is sum of solutions (i)
// 	// including coins[n-1] (ii) excluding coins[n-1]
// 	return count(coins, n, sum - coins[n - 1])
// 		+ count(coins, n - 1, sum);
// }

// // Driver code
// int main()
// {
// 	int i, j;
// 	int coins[] = { 1, 2, 3 };
// 	int n = sizeof(coins) / sizeof(coins[0]);
// 	int sum = 5;

// 	cout << " " << count(coins, n, sum);

// 	return 0;
// }
