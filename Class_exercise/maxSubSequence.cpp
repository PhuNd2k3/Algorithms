// CPP
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> A;
#define oo 1e7
void input()
{
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

int maxLeft(int i, int j)
{
    int res = -oo;
    int s = 0;
    for (int k = j; k >= i; k--)
    {
        s += A[k];
        if (s > res)
            res = s;
    }
    return res;
}
int maxRight(int i, int j)
{
    int res = -oo;
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += A[k];
        if (s > res)
            res = s;
    }
    return res;
}

int maxSubSeq(int l, int r)
{
    if (l == r)
        return A[l];
    int m = (l + r) / 2;
    int ML = maxSubSeq(l, m);
    int MR = maxSubSeq(m + 1, r);
    int MLR = maxLeft(l, m) + maxRight(m + 1, r);
    return max(max(ML, MR), MLR);
}

int maxSubSeqDP()
{
    int res = -oo;
    vector<int> S;
    S.resize(n);
    S[0] = A[0];
    for (int i = 2; i < n; i++)
    {
        if (S[i - 1] > 0)
            S[i] = S[i - 1] + A[i];
        else
            S[i] = A[i];
        if (S[i] > res)
            res = S[i];
    }
    return res;
}

int main()
{
    input();
    // cout << maxSubSeq(0, n - 1);
    cout << maxSubSeqDP();
    return 0;
}