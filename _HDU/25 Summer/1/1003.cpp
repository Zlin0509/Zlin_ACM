//
// Created by 27682 on 2025/7/18.
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
typedef unsigned long long ull;

int pnum;

struct Bitset {
    ull pool[60]{};

    Bitset() { memset(pool, 0, sizeof(pool)); }

    ull &operator[](const int i) { return pool[i]; }

    void set(const int i) { pool[i / 64] |= 1ull << i % 64; }

    bool check(const int i) { return pool[i / 64] >> i % 64 & 1; }
} sz;

constexpr int N = 3010;

int n, len, w[17], m;
string s;

inline void Zlin() {
    cin >> n >> s;
    // for (int i = 0; i < n; i++) cin >> w[s[i] - 'a'];
    for (int i = 0; i < 17; i++) cin >> w[i];
    cin >> len;
    if (n & 1 && len & 1 && n == len) {
        cout << 0 << endl;
        return;
    }
    if (len & 1) ++len;
    m = n - len + 1;
    pnum = m / 64 + 1;
    Bitset bs[18], tmp;
    for (int i = 0; i < m; i++) {
        for (int j = 0, idx; j < len; j++) {
            if (s[i + j] < s[i + len - 1 - j]) {
                idx = s[i + j] - 'a';
                bs[idx].set(i);
            } else if (s[i + j] == s[i + len - 1 - j]) bs[17].set(i);
        }
    }
    int ans = 1e9, res;
    for (int i = 0; i < 1 << 17; i++) {
        for (int k = 0; k < pnum; k++) tmp[k] = bs[17][k];
        res = 0;
        for (int j = 0; j < 17; j++) {
            if (i >> j & 1) {
                res += w[j];
                for (int k = 0; k < pnum; k++) tmp[k] |= bs[j][k];
            }
        }
        bool check = true;
        for (int j = 0; j < m; j++) {
            if (!tmp.check(j)) {
                check = false;
                break;
            }
        }
        if (check) ans = min(ans, res);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
