// CPP
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> A; // Danh sách kề

vector<bool> visited;

void BFS(int k)
{
    queue<int> conected_queue;
    conected_queue.push(k);
    visited[k] = true;

    while (!conected_queue.empty())
    {
        int i = conected_queue.front();
        conected_queue.pop();
        visited[i] = true;

        for (int j : A[i])
        {
            if (!visited[j])
                conected_queue.push(j);
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    A.resize(N);
    visited.assign(N, false);
    N = min(N, 100000);
    M = min(M, 100000);

    int i, j;
    for (int k = 0; k < M; k++)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        i--;
        j--;
        A[i].push_back(j);
        A[j].push_back(i);
    }

    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            BFS(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
