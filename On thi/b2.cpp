#include <bits/stdc++.h>
#include <string>

#define N 1000
#define MOD 1000000007
using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    int l = str.length();
    if (str[0] == '+')
    {
        cout << "NOT_CORRECT" << endl;
        return 0;
    }
    else
    {
        int i = 0;
        while (isdigit(str[i]))
        {
            i++;
        }
        sum += stoi(str.substr(0, i));
    }
    for (int i = 1; i < l; i++)
    {
        if (str[i] == '+')
        {
            if (str[i + 1] == '+' || i == (l - 1))
            {
                cout << "NOT_CORRECT" << endl;
                return 0;
            }
            else
            {
                int j = i + 1;
                while (isdigit(str[j]))
                {
                    j++;
                }
                sum += stoi(str.substr(i + 1, j));
                sum = sum % MOD;
            }
        }
    }
    sum = sum % MOD;
    cout << sum << endl;
    return 0;
}