//
// Created by 27682 on 2025/10/13.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6 + 5;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;
    int maxn = a[0], ans = 0;
    auto cal = [](int x, int y) {
        return x % y + y % x;
    };
    cout << 0 << ' ';
    for (int i = 1; i < n; i++) {
        ans = max(ans, cal(a[i], maxn));
        if (a[i] > maxn) {
            if (a[i] >= maxn * 2) {
                maxn = a[i];
                for (int j = 0; j < i; j++) {
                    ans = max(ans, cal(a[j], maxn));
                }
            } else ans = maxn = a[i];
        }
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
