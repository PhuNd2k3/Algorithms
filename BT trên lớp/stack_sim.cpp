// C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int stackSimulator[100];
    int i = 0;
    while (true)
    {
        string k;
        cin >> k;
        if (k == "#")
            break;
        if (k == "PUSH")
        {
            int n;
            cin >> n;
            stackSimulator[i] = n;
            i++;
        }
        if (k == "POP")
        {
            if (i == 0)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << stackSimulator[--i] << endl;
            }
        }
    }
    return 0;
}