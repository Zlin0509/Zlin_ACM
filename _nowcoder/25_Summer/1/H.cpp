//
// Created by 27682 on 2025/7/15.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

constexpr int N = 1e6 + 10;
constexpr int psiz = 1 << 16;


struct Bitset {
    ull pool[16000]{};

    Bitset() { memset(pool, 0, sizeof(pool)); }

    ull &operator[](const int i) { return pool[i]; }

    void set(const int i) { pool[i / 64] |= 1ull << i % 64; }

    void flip(const int l, const int r) {
        if (l > r) return;
        if (l / 64 == r / 64) {
            for (int i = l % 64; i <= r % 64; i++) pool[l / 64] ^= 1ull << i;
            return;
        }
        pool[l / 64] ^= ~0ull << (l % 64);
        for (int i = l / 64 + 1; i < r / 64; i++) pool[i] = ~pool[i];
        pool[r / 64] ^= ~0ull >> (63 - r % 64);
    }
} t;

Bitset operator^(Bitset a, Bitset b) {
    Bitset res;
    for (int i = 0; i < 16000; i++) res[i] = a[i] ^ b[i];
    return res;
}

Bitset operator >>(Bitset a, int x) {
    Bitset res;
    int k = x / 64, t = x % 64;
    for (int i = 0; i < 16000 - k; i++) res[i] = a[i + k];
    if (t) {
        for (int i = 0; i < 16000 - 1; i++) {
            res[i] >>= t;
            res[i] ^= res[i + 1] << (64 - t);
        }
    }
    return res;
}

Bitset operator <<(Bitset a, int x) {
    Bitset res;
    int k = x / 64, t = x % 64;
    for (int i = 0; i < 16000 - k; i++) res[i + k] = a[i];
    if (t) {
        for (int i = 16000 - 1; ~i; i--) {
            res[i] <<= t;
            res[i] ^= res[i - 1] >> (64 - t);
        }
    }
    return res;
}

int n, q;
string s;
vi st;

ll val[psiz], sub[psiz], pre[psiz];

inline void init() {
    for (int i = 0, len; i < psiz; i++) {
        len = 0;
        for (int k = 0; k < 16; k++) {
            if (i >> k & 1) {
                if (k - len) val[i] += len * (len + 1) / 2;
                else pre[i] = len;
                len = 0;
            } else ++len;
        }
        sub[i] = len;
    }
}

inline void Zlin() {
    init();
    cin >> n >> q >> s;
    for (int i = 0; i < n; i++) if (s[i] == '1') t.set(i);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            st.emplace_back(l - 1), st.emplace_back(r);
        } else {
            int l, a, b;
            cin >> l >> a >> b;
            sort(st.begin(), st.end());
            for (int i = 0; i < st.size(); i += 2) t.flip(st[i], st[i + 1] - 1);
            st.clear();
            Bitset z = t >> (a - 1) ^ t >> (b - 1);
            ll len = 0, ans = 0;
            for (int i = 0; i < l / 64; i++) {
                ull tmp = z[i];
                for (int j = 0; j < 4; j++) {
                    ull now = tmp % psiz;
                    tmp /= psiz;
                    if (!now) len += 16;
                    else {
                        len += pre[now];
                        ans += len * (len + 1) / 2 + val[now];
                        len = sub[now];
                    }
                }
            }
            for (int i = 0; i < l % 64; i++) {
                if (z[l / 64] >> i & 1) {
                    ans += len * (len + 1) / 2;
                    len = 0;
                } else ++len;
            }
            ans += len * (len + 1) / 2;
            cout << ans << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    Zlin();
    return 0;
}
