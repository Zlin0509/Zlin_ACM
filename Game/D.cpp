//
// Created by Zlin on 2025/3/9.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin()
{
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++)
    {
        if (!k)
            break;
        int id = i;
        for (int j = 1; j <= k && i + j < s.length(); j++)
        {
            if (s[i + j] <= s[id])
                continue;
            id = i + j;
        }
        for (int j = id; j > i; j--)
            swap(s[j], s[j - 1]);
        k -= id - i;
    }
    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
