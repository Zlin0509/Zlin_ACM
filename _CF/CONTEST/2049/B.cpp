//
// Created by Zlin on 2024/12/20.
//

#include "bits/stdc++.h"

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
    int n;
    cin >> n;
    string a;
    cin >> a;
    vi ans(n);
    int tag = 1, l = 0, r = n;
    for (int i = n - 1; ~i; i--)
    {
        if (a[i] != 's') continue;
        l = i;
        while (l < r)
        {
            ans[l] = tag++;
            ++l;
        }
        r = i;
    }
    if (!ans[0])
    {
        l = 0;
        while (l < r)
        {
            ans[l] = tag++;
            ++l;
        }
    }
    // for (auto it : ans) cout << it << ' ';
    // cout << '\n';
    set<int> check;
    for (int i = 0; i < n; i++)
    {
        check.insert(ans[i]);
        if (a[i] != 'p') continue;
        if (*check.rbegin() != check.size())
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
