// CPP
#include <bits/stdc++.h>
using namespace std;

// vector<int> sc;
// vector<int> sl;
// vector<int> m;

long long int m[1000000 + 1];
long long int sc[1000000 + 1];
long long int sl[1000000 + 1];
bool markC[1000000 + 1];
bool markL[1000000 + 1];
long long int n;

// void input()
// {
//     cin >> n;
//     long long int tmp;
//     for (long long int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         m[i] = tmp;
//     }
// }

void input() {
    // Đọc dữ liệu từ file hoặc từ cin nếu bạn muốn nhập từ bàn phím
    ifstream inputFile("input.txt");

    // Kiểm tra xem file có mở thành công không
    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        exit(1);
    }

    // Đọc n từ file
    inputFile >> n;

    // Đọc dãy số từ file và lưu vào mảng m
    for (int i = 0; i < n; ++i) {
        inputFile >> m[i];
    }

    // Đóng file
    inputFile.close();
}

void even(long long int i)
{
    if (markC[i - 1] && sc[i - 1] > 0)
    {
        sc[i] = sc[i - 1] + m[i];

        markC[i] = true;
    }
    else
    {
        sc[i] = m[i];

        markC[i] = true;
    }

    if (markL[i - 1] && sl[i - 1] > 0)
    {
        sl[i] = sl[i - 1] + m[i];

        markL[i] = true;
    }
}

void odd(long long int i)
{
    if (markC[i - 1] && sc[i - 1] > 0)
    {
        sl[i] = sc[i - 1] + m[i];

        markL[i] = true;
    }
    else
    {
        sl[i] = m[i];

        markL[i] = true;
    }

    if (markL[i - 1])
    {
        sc[i] = sl[i - 1] + m[i];

        markC[i] = true;
    }
}

void maxEvenSubSeq()
{
    if (m[0] % 2 == 0)
    {
        sc[0] = m[0];
        markC[0] = true;
    }
    else
    {
        sl[0] = m[0];
        markL[0] = true;
    }

    for (long long int i = 1; i < n; i++)
    {
        if (m[i] % 2 == 0)
            even(i);
        else
            odd(i);
    }

    // long long int max = -99999999;
    // for (long long int i = 0; i < n; i++)
    // {
    //     if (markC[i])
    //     {
    //         max = max > sc[i] ? max : sc[i];
    //     }
    // }
    auto maxElement = max_element(begin(sc), end(sc));
    cout << *maxElement << endl;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    for (long long int i = 0; i < n; i++)
    {
        markC[i] = false;
        markL[i] = false;
    }
    input();
    maxEvenSubSeq();

    return 0;
}