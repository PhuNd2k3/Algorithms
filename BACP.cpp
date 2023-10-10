// CPP
#include <bits/stdc++.h>
using namespace std;

int N, M; // N mon M ky hoc
int A[16][16];
int loadMin = std::numeric_limits<int>::max();

int xk[16];  // xep mon k vao ky v
int c[16];   // so tin chi cua mon
int load[5]; // so tin chi cua ky i

bool check(int v, int k)
{
    for (int i = 0; i < N; i++) // chi xet cac mon truoc mon k vi cac mon sau no chua duoc xep
    {
        if (A[i][k])
        {
            if (xk[i] >= v)
                return false;
        }
        else if (A[k][i])
        {
            if (v >= xk[i])
                return false;
        }
    }
    return true;
}

void solution()
{
    int *maxLoad = max_element(load, load + N);
    loadMin = loadMin < *maxLoad ? loadMin : *maxLoad;
}

void Try(int k) // thu xep mon thu k vao ky v
{
    for (int v = 0; v < M; v++)
    {
        if (check(v, k))
        {
            xk[k] = v;
            load[v] += c[k];
            if (k == (N - 1))
                solution();
            else if (load[v] < loadMin)
                Try(k + 1);
            load[v] -= c[k];
        }
    }
}

int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    Try(0);
    cout << loadMin << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << i + 1 << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < N; i++)
    // {
    //     cout << xk[i] << " ";
    // }
    return 0;
}