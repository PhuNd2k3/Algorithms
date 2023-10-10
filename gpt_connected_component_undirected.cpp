#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj; // Danh sách kề
vector<bool> visited;

int BFS(int start)
{
    int count = 0;
    queue<int> connected_queue;
    connected_queue.push(start);
    visited[start] = true;

    while (!connected_queue.empty())
    {
        int current = connected_queue.front();
        connected_queue.pop();

        for (int neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                connected_queue.push(neighbor);
            }
        }
    }

    return 1;
}

int main()
{
    int N, M;
    cin >> N >> M;
    adj.resize(N);
    visited.assign(N, false);

    for (int k = 0; k < M; k++)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    int components = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            components += BFS(i);
        }
    }

    cout << components << endl;
    return 0;
}
