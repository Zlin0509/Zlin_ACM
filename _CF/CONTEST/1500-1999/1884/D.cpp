//
// Created by Zlin on 2025/3/20.
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

constexpr int N = 1e6 + 5;

int f[N], siz[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    if (fx > fy) swap(fx, fy);
    f[fy] = fx;
    siz[fx] += siz[fy];
}

vector<int> fac(N);



inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end(), greater<int>());
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
