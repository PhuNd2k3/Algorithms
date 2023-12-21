#include <bits/stdc++.h>
#define MAX_N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loopdown(i, a, b) for (int i = a; i >= b; i--)

using namespace std;
int N, M, n, m;
int a[MAX_N];
int b[MAX_N];
int fdigit = 0;
int f[MAX_N];
int countDigit(int k)
{
    int count = 0;
    while (k > 0)
    {
        /* code */
        k = k / 10;
        count++;
    }
    return count;
}

void checkArray(int arr[], int size)
{
    loop(i, 1, size)
    {
        cout << arr[i];
    }
    cout << endl;
}

void fplus(int index, int k)
{
    if (f[index] + k > 9)
    {
        f[index] = (f[index] + k) % 10;
        fplus(index - 1, 1);
    }
    else
    {
        f[index] = (f[index] + k);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    string str1, str2;
    cin >> str1;
    cin >> str2;
    n = str1.size();
    m = str2.size();
    fdigit = n + m;
    // cout << n << " " << m << " " << fdigit << endl;
    loop(i, 1, fdigit)
    {
        a[i] = 0;
        b[i] = 0;
    }
    int j = 0;
    loopdown(i, fdigit, 1)
    {
        if (n - j > 0)
        {
            a[fdigit - j] = str1[n - j - 1] - '0';
        }
        if (m - j > 0)
        {
            b[fdigit - j] = str2[m - j - 1] - '0';
        }
        j++;
    }
    //
    //
    //
    //
    int c1, c2, c3;
    int digitc2;
    int fplusvalue;
    // a-n b-m
    loopdown(i, fdigit, fdigit - m + 1)
    {
        // c2 = 0;
        // c3 = 1;
        loopdown(j, fdigit, fdigit - n + 1)
        {
            c1 = a[j] * b[i];
            // c2 += c1;
            // c3 = c3 * 10;
            fplus(j + i - fdigit, c1 % 10);
            fplus(j + i - fdigit - 1, c1 / 10);
            // checkArray(f, fdigit);
        }
        // cout << c2 << endl;
        // digitc2 = countDigit(c2);
        // loopdown(k, i, i - digitc2 + 1)
        // {
        //     fplusvalue = c2 % 10;
        //     c2 = c2 / 10;
        //     fplus(k, fplusvalue);
        // }
        // checkArray(f, fdigit);
    }
    int flag = 1;
    while (f[flag] == 0)
        flag++;
    loop(i, flag, fdigit)
    {
        cout << f[i];
    }
    return 0;
}