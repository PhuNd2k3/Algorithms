// CPP
#include <bits/stdc++.h>
using namespace std;

const unsigned long long MOD = 1000000007;

unsigned long long mod_pow(unsigned long long a, unsigned long long b, unsigned long long mod)
{
    unsigned long long result = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % mod;
        }
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;

    unsigned long long result = mod_pow(a, b, MOD);
    cout << result << endl;

    return 0;
}
