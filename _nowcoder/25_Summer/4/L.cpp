//
// Created by 27682 on 2025/7/24.
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

constexpr int N = 2e5 + 10;

ll n, q;
ll a[N], b[N];

vi pos;

int find(int lx, int rx) {
    int l = 0, r = pos.size(), mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (pos[mid] <= rx) l = mid;
        else r = mid - 1;
    }
    if (pos[l] >= lx && pos[l] <= rx) return pos[l] - lx + 1;
    return -1;
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!(a[i] + b[i - 1] & 1)) pos.emplace_back(i);
        b[i] = (b[i - 1] + a[i]) >> 1;
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll id = n - y + 1, idx = upper_bound(a, a + 1 + n, x) - a;
        if (idx > id) {
            cout << 0 << endl;
        } else {
            if (id - idx + 1 < 500) {
                ll ans = 0;
                for (int i = idx; i <= id; i++) {
                    ll len = (a[i] - x + 1) / 2;
                    x += len;
                    ans += len;
                }
                cout << ans << endl;
            } else {
                int ed = find(id, idx), cnt = 0;
                while (x >= 2) {
                    ++cnt;
                    x /= 2;
                }
                if (cnt > ed) cout << b[id] + 2 - x << endl;
                else cout << b[id] + 1 - x << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
