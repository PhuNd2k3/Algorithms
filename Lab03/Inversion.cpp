#include <bits/stdc++.h>
#define N 1000001
#define M 1000000007
using namespace std;

int n;
int a[N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << " ";
    }
}

long long int merge1(int left, int right, int mid)
{
    // cout << "Merge" << endl;
    long long int inverse = 0;
    sort(a + left, a + mid + 1);
    sort(a + mid + 1, a + right + 1);
    // cout << "Left: ";
    // printArray(left, mid);
    // cout << endl;
    // cout << "Right: ";
    // printArray(mid + 1, right);
    // cout << endl;
    int start = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        int j = start;
        if (a[i] <= a[j])
            continue;
        // a[i] > a[j]
        if (a[i] > a[right])
        {
            inverse += (right - j + 1) * (mid - i + 1);
            break;
        }
        while (a[i] > a[j] && j <= right)
        {
            start++;
            inverse += (mid - i + 1);
            j++;
        }
    }
    // cout << "Inverse: " << inverse << endl;
    return inverse;
}

int merge(int left, int right, int mid)
{
    int inverse = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;

    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            inverse = (inverse + (mid - left - i + 1)) % M;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    // cout << "Inverse: " << inverse << endl;

    return inverse % M;
}

int inversion(int left, int right)
{
    if (left == right)
        return 0;
    if (left == (right - 1))
    {
        if (a[left] > a[right])
        {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
            return 1;
        }
        else
            return 0;
    }
    int mid = (left + right) / 2;
    // int count = 0;
    // count = (count + inversion(left, mid)) % M;
    // count = (count + inversion(mid + 1, right)) % M;
    // count = (count + merge(left, right, mid)) % M;
    // if (mid == (n - 1) / 2)
    //     cout << "Mid: " << endl;
    // return count;
    return (inversion(left, mid) + inversion(mid + 1, right) + merge(left, right, mid)) % M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    input();
    int left = 0;
    int right = n - 1;
    cout << inversion(left, right);
    return 0;
}