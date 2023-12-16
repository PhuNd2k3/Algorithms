#include <bits/stdc++.h>
#define N 100001
#define T 50
using namespace std;

int t;
int n;
int c[T]; // luu so c cho moi truong hop T
int d[T]; // luu ket qua cho moi truong hop T
vector<int> cVector[T];
bool visited[N];
int route = 0;
int res[N]; // luu ket qua chon C cho moi truong hop
void input()
{
    cin >> t;
    int v;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> c[i];
        for (int j = 0; j < n; j++)
        {
            cin >> v;
            cVector[i].push_back(v);
        }
        sort(cVector[i].begin(), cVector[i].end());
    }

    // for (int i = 0; i < t; i++)
    // {
    //     cout << n << " " << c[i] << endl;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << cVector[i][j] << endl;
    //     }
    // }
}
int ac;
int a1;
double k1;
double kmax;

double comparevalue;

bool compare(int a, int b)
{
    auto ita = find(cVector[route].begin(), cVector[route].end(), a);
    int indexa = distance(cVector[route].begin(), ita) - 1;
    auto itb = find(cVector[route].begin(), cVector[route].end(), b);
    int indexb = distance(cVector[route].begin(), itb) - 1;
    if (visited[indexa] == true && visited[indexb] == false)
        return false;
    if (visited[indexa] == false && visited[indexb] == true)
        return true;
    return abs(a - comparevalue) < abs(b - comparevalue);
}

int choose(int k)
{
    vector<int> toFind = cVector[route];
    int closest;
    comparevalue = res[k - 1] + k1;
    closest = *min_element(toFind.begin(), prev(toFind.end()), compare);
    auto it = find(toFind.begin(), toFind.end(), closest);
    int index = distance(toFind.begin(), it);
    visited[--index] = true;
    // cout << closest << endl;
    // cout << index << endl;
    return closest;
}

void solution()
{
    d[route] = d[route] < kmax ? kmax : d[route];
    d[route] = d[route] < ac - kmax ? d[route] : ac - kmax;
    // for (int i = 0; i < c[route]; i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
}

void Try(int k)
{
    while (kmax > d[route])
    {
        res[k] = choose(k);
        kmax = kmax < (res[k] - res[k - 1]) ? kmax : (res[k] - res[k - 1]);
        // kmax = kmax < (ac - res[k]) ? kmax : (ac - res[k]);
        if (k == (c[route] - 2))
        {
            solution();
        }
        else
        {
            if ((res[k] + k1) < ac)
            {
                Try(k + 1);
            }
            else
                break;
        }
    }
}

void solve()
{
    a1 = *min_element(cVector[route].begin(), cVector[route].end()); // chon 0
    ac = *max_element(cVector[route].begin(), cVector[route].end()); // chon c - 1
    res[0] = a1;
    res[c[route] - 1] = ac;
    visited[0] = true;
    visited[c[route] - 1] = true;
    // con can chon c-2
    k1 = (a1 + ac) / (c[route] - 2);
    kmax = k1;
    Try(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    for (int i = 0; i < t; i++)
    {
        d[t] = INT_MAX;
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
            visited[j] = false;
        d[i] = INT_MIN;
        solve();
        route++;
        cout << d[i] << endl;
    }
    return 0;
}