// CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<string> DB;
    while (true)
    {
        string k;
        cin >> k;
        if (k == "*")
            break;
        DB.insert(k);
    }
    while (true)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "***")
            break;
        else if (cmd == "find")
        {
            string k;
            cin >> k;
            int res = 0;
            if (DB.find(k) != DB.end())
                res = 1;
            cout << res << endl;
        }
        else if (cmd == "insert")
        {
            string k;
            cin >> k;
            int res = 1;
            if (DB.find(k) != DB.end())
                res = 0;
            else
                DB.insert(k);
            cout << res << endl;
        }
    }
    return 0;
}