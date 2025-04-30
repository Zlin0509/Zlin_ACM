//
// Created by Zlin on 2025/1/23.
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
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << "NO" << endl;
        return;
    }
    vector<char> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = 'a' + i % 26;
    ans[n - 1] = ans[m - 1];
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
        mp[ans[i]] = i;
    int check = 0;
    for (int i = 0; i < n; i++)
        if (mp[ans[i]] > i)
            check = i + 1;
    if (check != m)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (auto it : ans)
        cout << it;
    cout << endl;
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
