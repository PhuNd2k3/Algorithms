// CPP
#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b;

const unsigned long long MOD = 1000000007;
unsigned long long mod = MOD;
unsigned long long power()
{

    unsigned long long result = 1;
    // a^b mod q = (a mod q)^b mod q
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * (a % mod)) % mod;
        }
        b = b >> 1; // dich phai 1 bit
        a = (a * a) % mod;
    }
    return result;
}

int main()
{
    cin >> a >> b;

    unsigned long long result = power();
    cout << result;

    return 0;
}
