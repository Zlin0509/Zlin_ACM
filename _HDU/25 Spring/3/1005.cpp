//
// Created by 27682 on 2025/3/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 3e5 + 10;

int f[N], siz[N];

inline int find(int u)
{
    if (f[u] == u)
        return u;
    return f[u] = find(f[u]);
}

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    if (fx > fy)
        swap(fx, fy);
    f[fy] = fx;
    siz[fx] += siz[fy];
}

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[i] = i, siz[i] = 1;
    for (int i = 1, tag; i <= n; i++)
    {
        tag = i + a[i];
        if (tag <= n)
            merge(i, tag);
        tag = i - a[i];
        if (tag >= 1)
            merge(i, tag);
    }
    vi used(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!used[find(i)])
        {
            ++ans;
            used[f[i]] = 1;
        }
    cout << ans - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
