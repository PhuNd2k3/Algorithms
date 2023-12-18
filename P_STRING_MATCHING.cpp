// C++ program for implementation of KMP pattern searching
// algorithm

#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int M, int *lps);
int f = 0;
// Prints occurrences of pat[] in txt[]
void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            f++;
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(string pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    KMPSearch(str1, str2);
    cout << f;
    return 0;
}

// int k = 0;
// int check = 0;
// loop(i, 0, m - 1)
// {
//     k = i;
//     check = 0;
//     loop(j, 0, n - 1)
//     {
//         if (str2[k] == str1[j])
//         {
//             // cout << k << " : " << str2[k] << endl;
//             k++;
//             check++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     if (check == n)
//         f++;
// }