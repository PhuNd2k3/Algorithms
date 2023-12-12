#include <bits/stdc++.h>
#define N 10000001

using namespace std;
int n = 0;
int m = 0;
vector<int> a[N];
int visited[N];

int cc = 0;

// void dfs(int u)
// {
//     visited[u] = true;
//     for (int e : a[u])
//     {
//         if (!visited[e])
//         {
//             // visited[e] = true;
//             dfs(e);
//         }
//     }
// }

void dfs(int u)
{
    stack<int> stack;
    stack.push(u);
    int v;
    while (!stack.empty())
    {
        v = stack.top();
        stack.pop();
        visited[v] = true;
        for (int e : a[v])
        {
            if (!visited[e])
                stack.push(e);
        }
    }
}

void input()
{
    string s;
    int v1, v2;
    while (1)
    {
        cin >> s;
        if (s == "#")
            break;
        cin >> v1 >> v2;
        n++;
    }
    string s1, s2;
    while (1)
    {
        cin >> s;
        if (s == "#")
            break;
        cin >> s1 >> s2;
        v1 = stoi(s1.substr(1));
        v2 = stoi(s2.substr(1));
        m++;
        a[v1 - 1].push_back(v2 - 1);
        a[v2 - 1].push_back(v1 - 1);
    }
    // for (const auto &pair : db_riu)
    // {
    //     cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    // }
}

int longest_cycle;
int start;

bool check(int v, int k)
{
    return (visited[v] == false);
}

void solution()
{
}

void Try(int k, int l)
{
    for (int v : a[l])
    {
        if (check(v, k))
        {
            visited[v] = true;
            auto it = find(a[v].begin(), a[v].end(), start);

            if (it != a[v].end())
            {
                longest_cycle = max(longest_cycle, k + 1);
            }
            if ((k == n) || (longest_cycle == n))
            {
                solution();
            }
            else
            {
                Try(k + 1, v);
                visited[v] = false;
            }
        }
    }
}

void solve()
{
    // cout << "Calling solution" << endl;
    string s;
    while (1)
    {
        cin >> s;
        if (s == "###")
            break;
        if (s == "?connected_components")
        {
            for (int i = 0; i < N; i++)
                visited[i] = false;
            for (int i = 0; i < n; i++)
            {
                if (!visited[i])
                {
                    dfs(i);
                    cc++;
                }
            }
            cout << cc << endl;
        }
        if (s == "?number_points")
        {
            // cout << s << endl;
            cout << n << endl;
        }
        if (s == "?number_segments")
            cout << m << endl;
        if (s == "?longest_cycle_from")
        {
            string point;
            cin >> point;
            start = stoi(point.substr(1));
            for (int i = 0; i < N; i++)
                visited[i] = false;
            longest_cycle = 0;
            visited[start] = true;
            Try(1, start);
            cout << longest_cycle << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    freopen("phudeptrai.txt", "r", stdin);
    input();

    solve();
    return 0;
}

//     // Khởi tạo một pair với các giá trị khác nhau kiểu int và double
//     pair<int, double> myPair(42, 3.14);

//     // Truy cập và in ra giá trị của first và second
//     cout << "First: " << myPair.first << ", Second: " << myPair.second << endl;

//     // Sử dụng phương thức first và second
//     int value1 = myPair.first();
//     double value2 = myPair.second();

//     cout << "Value 1: " << value1 << ", Value 2: " << value2 << endl;

//     // Sử dụng phương thức swap
//     pair<int, double> anotherPair(100, 2.718);
//     myPair.swap(anotherPair);

// // Khai báo map
//     map<int, string> myMap;

//     // Chèn phần tử vào map
//     myMap.insert(make_pair(1, "One"));
//     myMap[2] = "Two";
//     myMap[3] = "Three";

//     // Truy cập giá trị thông qua key
//     cout << "Value for key 2: " << myMap[2] << endl;

//     // Tìm kiếm key trong map
//     auto it = myMap.find(3); //intergator
//     if (it != myMap.end()) {
//         cout << "Key 3 found, Value: " << it->second << endl;
//     } else {
//         cout << "Key 3 not found in the map." << endl;
//     }

//     // Kiểm tra sự tồn tại của key trong map
//     if (myMap.count(4) > 0) {
//         cout << "Key 4 exists in the map." << endl;
//     } else {
//         cout << "Key 4 does not exist in the map." << endl;
//     }

//     // Duyệt qua tất cả các phần tử trong map
//     for (const auto& pair : myMap) {
//         cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
//     }

//     // Xóa phần tử từ map
//     myMap.erase(2);

//     // Kiểm tra map có trống không
//     if (myMap.empty()) {
//         cout << "Map is empty." << endl;
//     } else {
//         cout << "Map is not empty." << endl;
//     }

//     // Số lượng phần tử trong map
//     cout << "Number of elements in the map: " << myMap.size() << endl;

//     // Xóa tất cả các phần tử từ map
//     myMap.clear();