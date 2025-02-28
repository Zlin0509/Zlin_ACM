//
// Created by Zlin on 2025/2/27.
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
    int n, k;
    cin >> n >> k;
    string s;
    vi a(n);
    cin >> s;
    for (int& it : a)
        cin >> it;
    auto check = [&](int x)
    {
        int res = 0;
        int l = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= x)
                continue;
            if (l == -1)
            {
                if (s[i] == 'B')
                    l = i;
            }
            else
            {
                if (s[i] == 'R')
                    ++res, l = -1;
            }
        }
        if (l != -1)
            ++res;
        return res <= k;
    };
    int l = 0, r = 2e9, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
