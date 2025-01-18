//
// Created by Zlin on 2025/1/16.
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

constexpr int N = 2e5 + 5;

ll fa[N], sum[N], cnt = 0, ans[N], used[N];
ll n;
ll a[N], b[N];

inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    fa[fx] = fy;
    sum[fy] += sum[fx];
    cnt = max(cnt, sum[fy]);
}

inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], fa[i] = i;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 0;i<=n+3;i++) used[i] = -1;
    for (int i = n; i >= 1; i--)
    {
        int tag = b[i];
        used[tag] = a[tag];
        sum[tag] = a[tag];
        cnt = max(cnt, sum[tag]);
        if (used[tag - 1] != -1) merge(tag, tag - 1);
        if (used[tag + 1] != -1) merge(tag, tag + 1);
        ans[i - 1] = cnt;
    }
    for (int i = 1; i <= n; i++)cout << ans[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
