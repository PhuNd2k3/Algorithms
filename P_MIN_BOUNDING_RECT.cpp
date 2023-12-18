#include <bits/stdc++.h>
#define N 1001
#define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n;
vector<double> vx;
vector<double> vy;
void doubleCheck()
{
    // sort(vx.begin(), vx.end());
    // sort(vy.begin(), vy.end());
    for (int i = 0; i < vx.size(); i++)
    {
        cout << vx[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vy.size(); i++)
    {
        cout << vy[i] << " ";
    }
    cout << endl;
}

void input()
{
    double l = INT_MIN;
    double r = INT_MAX;
    double u = INT_MIN;
    double d = INT_MAX;
    double x1, y1, x2, y2;
    double x, y;

    cin >> n;
    loop(i, 1, n)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        vx.push_back(x1);
        vx.push_back(x2);
        vy.push_back(y1);
        vy.push_back(y2);
        // doubleCheck();
        // x = (x1 + x2) / 2;
        // y = (y1 + y2) / 2;

        // vx.push_back(x - (y2 - y));
        // vx.push_back(x + (y2 - y));
        // vy.push_back(y - (x2 - x));
        // vy.push_back(y + (x2 - x));
        // doubleCheck();
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());

    l = vx[0];
    r = vx.back();
    d = vy[0];
    u = vy.back();
    cout << (r - l) * (u - d);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    return 0;
}