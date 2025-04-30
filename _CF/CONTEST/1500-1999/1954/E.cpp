//
// Created by 27682 on 2025/4/7.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 10;

int tot;
int f[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    --tot;
    f[fx] = fy;
}

inline void Zlin() {
    int n, m = 0;
    cin >> n;
    vi a(n);
    for (int &it: a) {
        cin >> it;
        m = max(it, m);
    }
    vector be(m + 1, vi());
    for (int i = 0; i < n; i++)
        be[a[i]].push_back(i);

    vll ans(m + 1), val(m + 1);

    tot = 0;
    for (int i = 0; i < n; i++) f[i] = i;

    for (int i = m; i; i--) {
        tot += be[i].size();
        for (int it: be[i]) {
            if (it > 0 && a[it - 1] >= a[it])
                merge(it, it - 1);
            if (it < n - 1 && a[it + 1] >= a[it])
                merge(it, it + 1);
        }
        val[i] = tot;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j += i) {
            ans[i] += val[j];
        }
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
