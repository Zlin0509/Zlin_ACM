//
// Created by Zlin on 2025/7/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 5010;
constexpr ll mo = 998244353;

ll f[N];

int n;
int tag[N * 2], vis[N * 2];

inline void Zlin() {
    cin >> n;
    fill(vis, vis + n * 2 + 1, 0);
    vis[n * 2 + 1] = -1;
    tag[n * 2 + 1] = n * 2;
    cout << f[n] << ' ';
    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        vis[r] = l;
        tag[r] = r - l - 1;
        for (int j = r - 1; j >= l + 1; j--) {
            if (vis[j]) {
                tag[r] -= tag[j] + 2;
            }
        }
        for (int j = r + 1; ; j++) {
            if (vis[j] && vis[j] < l) {
                tag[j] -= tag[r] + 2;
                break;
            }
        }
        ll ans = 1;
        for (int j = 0; j <= n * 2 + 1; j++) ans = ans * f[tag[j] >> 1] % mo;
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            f[i] = (f[i] + f[i - j] * f[j - 1]) % mo;
        }
    }
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
