#include <bits/stdc++.h>
#define N 1000
// #define loop(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

void input()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // input();
    // int d, mon, y;
    char dmy[N];
    int h, m, s;
    int duration;
    char buffer[N];
    char str[N][11];
    int n = 0;
    int convert[6] = {1, 60, 60 * 60, 60 * 60 * 24, 60 * 60 * 24 * 30, 60 * 60 * 24 * 30 * 365};
    //                s   m    h           day           month               year
    do
    {
        cin >> buffer;
        if (buffer[0] == '*')
            break;
        sscanf(buffer, "%s", str[n]);
        // cout << str[n] << endl;
        n++;
    } while (1);
    // cout << "END phase 1" << endl;
    int plus;
    do
    {
        // cout << "Run loop 2" << endl;
        cin.getline(buffer, sizeof(buffer));
        if (buffer[0] == '*')
            break;
        // cout << buffer << endl;
        sscanf(buffer, "%s %d:%d:%d %d", dmy, &h, &m, &s, &duration);
        duration = duration + s * convert[0] + m * convert[1] + h * convert[2];
        plus = duration / convert[3];
        duration -= convert[3] * plus;
        for (int i = 0; i < n; i++)
        {
            if (strncmp(str[i], dmy, 11) == 0)
            {
                printf("%s ", str[i + plus]);
                plus = duration / convert[2];
                duration -= convert[2] * plus;
                h = plus;
                plus = duration / convert[1];
                duration -= convert[1] * plus;
                m = plus;
                plus = duration / convert[0];
                duration -= convert[0] * plus;
                s = plus;
                printf("%02d:%02d:%02d\n", h, m, s);
                break;
            }
        }
    } while (1);

    return 0;
}