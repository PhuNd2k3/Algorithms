// CPP
#include <bits/stdc++.h>
using namespace std;

int N, M;          // M giao vien N mon hoc
vector<int> A[10]; // 10 hang cho giao vien va toi da 30 cot cho mon hoc
int loadMin = std::numeric_limits<int>::max();

int x[30]; // x[i] = j la mon i xep cho thay j

int conflict;
vector<int> c[30]; // danh sach conflict

bool check(int v, int k)
{
    return false;
}

void solution()
{
    // int *maxLoad = max_element(load, load + N);
    // loadMin = loadMin < *maxLoad ? loadMin : *maxLoad;
}

void Try(int k) // thu xep mon thu k cho thay v
{
    for (int v = 0; v < M; v++)
    {
        if (check(v, k))
        {

            if (k == (M - 1))
                solution();
            else
                Try(k + 1);
        }
    }
}

void checkInput()
{
    cout << M << endl;
    cout << N << endl;
    for (int i = 0; i < M; i++)
    {
        for (int element : A[i])
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << conflict << endl;
    for (int i = 0; i < conflict; i++)
    {
        for (int element : c[i])
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M;
    cin >> N;
    int k;
    int tmp;

    for (int i = 0; i < M; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            A[i].push_back(tmp);
        }
    }

    cin >> conflict;
    for (int i = 0; i < conflict; i++)
    {
        cin >> tmp;
        c[i].push_back(tmp);
    }

    // checkInput();
    Try(0);

    return 0;
}