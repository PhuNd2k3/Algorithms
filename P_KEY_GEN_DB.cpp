#include <bits/stdc++.h>
#define N 1000001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, L, m;

struct cmp
{
    bool operator()(string str1, string str2) { return stoi(str1) < stoi(str2); }
};
void Plus(string &key, int index)
{
    if (key[index] + 1 > '9')
    {
        key[index] = '0';
        Plus(key, index - 1);
    }
    else
    {
        key[index] += 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // input();
    set<string> DB;
    cin >> n >> L >> m;
    string str;
    string key;
    key.resize(L);
    loop(i, 1, L)
    {
        key[i - 1] = 48;
    }
    loop(i, 1, n)
    {
        cin >> str;
        DB.insert(str);
    }
    loop(i, 1, m)
    {
        Plus(key, L - 1);
        while (DB.find(key) != DB.end())
        {
            Plus(key, L - 1);
        }
        DB.insert(key);
    }
    // Plus(key, L - 1);
    // cout << key << endl;
    for (auto it = DB.begin(); it != DB.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}