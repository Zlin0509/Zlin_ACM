//
// Created by Zlin on 2025/1/20.
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

constexpr ll M = 1E9 + 7;
ll ans = 0;
int n, k, a, b;

vi f;
vll sum;

inline int find(int u)
{
    if (f[u] == u)
        return u;
    int x = find(f[u]);
    sum[u] = (sum[f[u]] + sum[u] + M) % M;
    f[u] = x;
    return f[u];
}

inline void Zlin()
{
    cin >> n;
    f.assign(n + 1, 0);
    sum.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> a >> b;
            int x = find(a);
            sum[x] = (sum[a] + b + M) % M;
            f[x] = i;
            ans = (ans + sum[x] + M) % M;
        }
    }
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--)Zlin();
    return 0;
}
