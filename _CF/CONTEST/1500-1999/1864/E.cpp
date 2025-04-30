//
// Created by 27682 on 2025/3/25.
//
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr ll mo = 998244353;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll ans;

struct Trie {
private:
    struct node {
        int val = 0;
        node *ls = nullptr, *rs = nullptr;
    };

    static const int N = 7e6;
    node pool[N];
    int tot = 0;

    node *root;

    node *alloc() {
        pool[tot] = {0, nullptr, nullptr};
        return &pool[tot++];
    }

public:
    void init() {
        tot = 0;
        root = alloc();
    }

    void ins(int s) {
        node *now = root;
        ll val;
        for (int i = 30, cnt = 0; ~i; i--) {
            val = cnt * 2 + 3;
            if (s >> i & 1) {
                if (now->ls != nullptr) {
                    val = now->ls->val * val;
                    ans = (ans + val) % mo;
                }
                if (now->rs == nullptr)
                    now->rs = alloc();
                now = now->rs;
                ++now->val;
                ++cnt;
            } else {
                if (now->rs != nullptr) {
                    val = now->rs->val * val;
                    ans = (ans + val) % mo;
                }
                if (now->ls == nullptr)
                    now->ls = alloc();
                now = now->ls;
                now->val++;
            }
        }
    }
} t;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    t.init();
    ans = 0;
    for (int &it: a) cin >> it, t.ins(it);

    // cout << ans << ' ';

    sort(a.begin(), a.end());
    for (int i = 1, cnt = 1, tag, val; i <= n; i++) {
        if (i != n && a[i] == a[i - 1])
            ++cnt;
        else {
            tag = a[i - 1];
            val = 1;
            for (int j = 30; ~j; j--)
                if (tag >> j & 1)
                    ++val;
            val = 1ll * cnt * cnt * val % mo;
            ans = (ans + val) % mo;
            cnt = 1;
        }
    }
    // cout << ans << ' ';
    ans = ans * qpow(1ll * n * n % mo, mo - 2) % mo;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
