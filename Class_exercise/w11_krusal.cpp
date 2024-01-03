#include <bits/stdc++.h>
using namespace std;

// Cấu trúc để lưu cạnh đồ thị,
// u, v là 2 đỉnh, w là trọng số cạnh
struct edge
{
    int u, v, w;
};
// Hàm so sánh để dùng trong hàm sort ở dưới
bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}

// Số đỉnh tối đa trong đề bài
#define N 100001

// 2 mảng sử dụng trong Disjoint Set
int cha[N], hang[N];

// Tìm xem u thuộc cây nào
int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}

// Hợp nhất 2 cây chứa u và v,
// Trả về false nếu không thể hợp nhất
bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (hang[u] == hang[v])
        hang[u]++;
    if (hang[u] < hang[v])
        cha[u] = v;
    else
        cha[v] = u;
    return true;
}

int main()
{
    // Thêm dòng này để cin, cout chạy nhanh
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    // Nhập vào số đỉnh và số cạnh
    int n, m;
    cin >> n >> m;

    // Nhập danh sách các cạnh
    vector<edge> edges(m);
    for (edge &e : edges)
        cin >> e.u >> e.v >> e.w;

    // Sắp xếp lại các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), cmp);

    // Khởi tạo cấu trúc Disjoint Set
    for (int i = 1; i <= n; i++)
    {
        cha[i] = i;
        hang[i] = 0;
    }

    // Lưu tổng trọng số các cạnh trong cây khung nhỏ nhất
    int mst_weight = 0;

    // Duyệt qua các cạnh theo thứ tự đã sắp xếp
    for (edge &e : edges)
    {
        // Thử hợp nhất 2 cây chứa u và v
        if (join(e.u, e.v))
        {
            // Hợp nhất thành công, ta thêm e và kết quả
            mst_weight += e.w;
        }
    }

    // Xuất kết quả
    cout << mst_weight;
    return 0;
}