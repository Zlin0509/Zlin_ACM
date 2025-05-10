//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll p = 11451413, mo = 1e9 + 7;
constexpr int N = 2e5 + 2e3;

int n, m, a[N];
ll fac[N], Hash1[N], Hash2[N];

bool check(int pos, int len) {
    ll lx = (Hash1[pos] - Hash1[pos - len] * fac[len] % mo + mo) % mo;
    ll rx = (Hash2[pos] - Hash2[pos + len] * fac[len] % mo + mo) % mo;
    return lx == rx;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vi have, now;
    for (int i = 2; i <= n; i++) have.push_back(a[i] - a[i - 1]);
    now.push_back(0);
    for (int i = 0; i < have.size(); i++) {
        now.push_back(have[i]);
        now.push_back(0);
    }

    have.push_back(0);
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    for (int &it: now) it = lower_bound(have.begin(), have.end(), it) - have.begin();

    int m = now.size();
    Hash1[0] = Hash2[m + 1] = 0;
    for (int i = 0; i < m; i++) Hash1[i + 1] = (Hash1[i] * p + now[i]) % mo;
    for (int i = m - 1; i >= 0; i--) Hash2[i + 1] = (Hash2[i + 2] * p + now[i]) % mo;

    ll ans = n;
    for (int i = 1, l, r, mid; i <= m; i++) {
        l = 1, r = min(i, m + 1 - i);
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (check(i, mid)) l = mid;
            else r = mid - 1;
        }
        ans += l >> 1;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * p % mo;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
