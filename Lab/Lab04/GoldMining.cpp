#include <bits/stdc++.h>
#define N 1000010
#define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int n;
int l1;
int l2;
int a[N];
long long int c[N];
int amax = 0;
void input()
{
    // cout << "Input" << endl;
    cin >> n >> l1 >> l2;
    loop(i, 1, n)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
}

void DP()
{
    loop(i, 1, l1) c[i] = *max_element(a + 1, a + i + 1);
    loop(i, l1 + 1, l2 + 1)
    {
        int v1 = *max_element(a + i - l1 + 1, a + i + 1);
        int v2 = a[i] + *max_element(i - l2 > 1 ? a + i - l2 + 1 : a + 1, a + i - l1 + 1);
        c[i] = max(v1, v2);
    }
    loop(i, l2 + 2, n)
    {
        int v2 = a[i] + *max_element(c + i - l2 + 1, c + i - l1 + 1);
        c[i] = max((long long int)v2, c[i - 1]);
    }
}

void input1()
{
    // cout << "Input" << endl;
    cin >> n >> l1 >> l2;
    loop(i, 0, n - 1)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
    }
}
void DP1()
{
    loop(i, 0, l1 - 1) c[i] = a[i];
    loop(i, l1, n - 1)
    {
        int v2 = a[i] + *max_element(i - l2 >= 0 ? c + i - l2 : c, c + i - l1 + 1);
        c[i] = v2;
    }
}

void printDeque(const deque<pair<long long int, int>> &dq)
{
    for (const auto &element : dq)
    {
        cout << "(" << element.first << ", " << element.second << ") ";
    }
    cout << endl;
}
deque<pair<long long int, int>> dq;
deque<pair<long long int, int>> dq_copy;

void pushPop(int i)
{
    // duyet qua a[y]-> a[x]
    int x = i - l1;
    int y = i - l2;
    if (x >= 0 && x < n)
    {
        // loai bo cac phan tu o cuoi hang doi ma co gia tri <= c[x]
        while (!dq.empty() && c[x] >= dq.back().first)
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(c[x], x));
    }
    if (y >= 0 && y < n)
    {
        // loai bo cac phan tu o dau hang doi ma co chi so < y
        if (!dq.empty() && y > dq.front().second)
        {
            dq.pop_front();
        }
    }
    // dq_copy = dq;
    // printDeque(dq_copy);
}

void DP1_improve()
{
    c[0] = a[0];
    loop(i, 1, n - 1)
    {
        pushPop(i);
        c[i] = (long long int)a[i];
        if (!dq.empty())
        {
            c[i] += dq.front().first;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("output3.txt", "w", stdout);
    input1();
    // DP1();
    DP1_improve();
    cout << *max_element(c + 1, c + n + 1);
    // input();
    // DP();
    // cout << c[n];
    return 0;
}
// cout << "Solving" << endl;
// Try(1);
// cout << Fmax;

// int c[N];
// int Fmax = INT_MIN;
// int f = 0;
// int g = 0;
// bool check(int v, int k)
// {
//     if (k == 1)
//         return true;
//     int index = v - c[k - 1];
//     if (index >= l1 && index <= l2)
//         return true;
//     return false;
// }

// void solution()
// {
//     Fmax = max(f, Fmax);
// }

// void printArray(int k)
// {
//     loop(i, 1, k) cout << c[i] << " ";
//     cout << endl;
// }

// void Try(int k)
// {
//     loop(v, k == 1 ? 1 : c[k - 1] + l1, n)
//     {
//         if (check(v, k))
//         {
//             c[k] = v;
//             f += a[v];
//             if (v + l1 > n)
//             {
//                 // printArray(k);
//                 solution();
//             }
//             else
//             {
//                 g = ((n - l1 - (v + l1)) / l1) + +2;
//                 if ((f + g * amax) > Fmax)
//                 {
//                     Try(k + 1);
//                 }
//             }
//             f -= a[v];
//         }
//     }
// }