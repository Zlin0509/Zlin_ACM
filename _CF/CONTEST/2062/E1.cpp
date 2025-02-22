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
    int max1 = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], max1 = max(max1, a[i]), cnt[a[i]]++;
    int tag = 0;
    if (cnt[max1] == 1)
    {
        int max2 = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] != max1)
                max2 = max(max2, a[i]);
        tag = max2;
    }
    else tag = max1;
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
