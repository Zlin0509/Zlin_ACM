//
// Created by Zlin on 2025/2/22.
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
    int n;
    cin >> n;
    vi a(n + 1);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;
    vector e(n + 1, vi());
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
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
