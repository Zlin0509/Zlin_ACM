//
// Created by Zlin on 2024/9/11.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;

int n, x, ans;
map<int, vi> place;
ll a[N], b[N];
ll f[N][22];

inline void ST_prework() {
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline int ST_query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void query(int l, int r) {
    int mx = ST_query(l, r);
    int begin = l, end = lower_bound(place[mx].begin(), place[mx].end(), l) - place[mx].begin();
    for (; end < place[mx].size() && place[mx][end] <= r; end++) {
        ++ans;
        if (b[place[mx][end] - 1] - b[begin - 1] >= mx) query(begin, place[mx][end] - 1);
        begin = place[mx][end] + 1;
    }
    if (begin <= r && b[r] - b[begin - 1] >= mx) query(begin, r);
}

inline void Zlin() {
    place.clear();
    ans = 0;
    cin >> n >> x;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        place[a[i]].push_back(i);
        mx = max(mx, a[i]);
        b[i] = b[i - 1] + a[i];
    }
    ST_prework();
    query(1, n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}