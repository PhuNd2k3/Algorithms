#include <bits/stdc++.h>
#define N 1000
// #define loop(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
map<pair<int, int>, int> level;
queue<pair<int, int>> q;
bool visited[N][N];
int A, B, C;
pair<int, int> tmp;
void input()
{
    cin >> A >> B >> C;
}

void solution(pair<int, int> v)
{
    if (v.first == C || v.second == C || v.first + v.second == C)
    {
        cout << level[v];
        exit(0);
    }
}

void fullA(pair<int, int> v, int step)
{
    if (!visited[A][v.second])
    {
        tmp.first = A;
        tmp.second = v.second;
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}
void fullB(pair<int, int> v, int step)
{
    if (!visited[v.first][B])
    {
        tmp.first = v.first;
        tmp.second = B;
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}
void AtoB(pair<int, int> v, int step)
{
    if (v.first + v.second > B)
    {
        tmp.first = v.first + v.second - B;
        tmp.second = B;
    }
    else
    {
        tmp.first = 0;
        tmp.second = v.first + v.second;
    }
    if (!visited[tmp.first][tmp.second])
    {
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}
void BtoA(pair<int, int> v, int step)
{
    if (v.first + v.second > A)
    {
        tmp.first = A;
        tmp.second = v.first + v.second - A;
    }
    else
    {
        tmp.first = v.second + v.first;
        tmp.second = 0;
    }
    // cout << tmp.first << " " << tmp.second << endl;
    // exit(0);
    if (!visited[tmp.first][tmp.second])
    {
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}

void outA(pair<int, int> v, int step)
{
    if (!visited[0][v.second])
    {
        tmp.first = 0;
        tmp.second = v.second;
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}
void outB(pair<int, int> v, int step)
{
    if (!visited[v.first][0])
    {
        tmp.first = v.first;
        tmp.second = 0;
        q.push(tmp);
        level[tmp] = step + 1;
        visited[tmp.first][tmp.second] = true;
        solution(tmp);
    }
}

void BFS()
{
    int current = 0;
    visited[0][0] = true;
    fullB({0, 0}, 0);
    fullA({0, 0}, 0);
    pair<int, int> v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        // if (level[v] != current)
        // {
        //     cout << "\nLevel " << level[v] << endl;
        //     current = level[v];
        // }
        // // cout << v.second << " " << v.first << endl;
        // cout << v.first << " " << v.second << endl;
        fullA(v, level[v]);
        fullB(v, level[v]);

        AtoB(v, level[v]);
        BtoA(v, level[v]);

        outA(v, level[v]);
        outB(v, level[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    // if (A > B)
    // {
    //     freopen("output.txt", "w", stdout);
    // }
    // else
    // {
    //     freopen("output2.txt", "w", stdout);
    // }
    if (C > A && C > B || C % __gcd(A, B) != 0)
        cout << -1 << endl;
    else
        BFS();
    return 0;
}