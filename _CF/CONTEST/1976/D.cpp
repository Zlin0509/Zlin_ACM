//
// Created by Zlin on 2024/9/26.
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
int s[N], n, f[N][32];
ll ans;
map<int, vi> have;

inline void ST_prework() {
    for (int i = 1; i <= n; i++)
        f[i][0] = s[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline int ST_query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void Zlin() {
    ans = 0;
    have.clear();
    string x;
    cin >> x;
    n = x.length();
    x = ' ' + x;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (x[i] == '(' ? 1 : -1);
    ST_prework();
    for (int i = 1; i <= n; i++) {
        int l = 0, r = have[s[i]].size() - 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (ST_query(have[s[i]][mid], i) <= s[i] * 2) r = mid;
            else l = mid + 1;
        }
        if (have[s[i]].size() && ST_query(have[s[i]][l], i) <= s[i] * 2)
            ans += have[s[i]].size() - l;
        have[s[i]].push_back(i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}