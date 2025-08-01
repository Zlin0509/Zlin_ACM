//
// Created by Zlin on 2025/8/1.
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

constexpr int N = 1e6 + 10;

int lx[N], rx[N];

struct AC_auto {
private:
    struct node {
        int val = 1e7;
        node *nex = nullptr;
        node *next[26] = {nullptr};
        node() { val = 1e7; }
    };

    static const int N = 1e6 + 5;
    node pool[N];
    int tot = 0;

    node *alloc() {
        pool[tot] = node();
        return &pool[tot++];
    }

    node *root;

public:
    void init() {
        tot = 0;
        root = alloc();
    }

    void ins(const string &s, int val) {
        node *now = root;
        for (char it: s) {
            if (now->next[it - 'a'] == nullptr)
                now->next[it - 'a'] = alloc();
            now = now->next[it - 'a'];
        }
        now->val = min(now->val, val);
    }

    void build() {
        queue<node *> q;
        root->nex = root;
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != nullptr)
                q.push(root->next[i]);
            else
                root->next[i] = root;
            root->next[i]->nex = root;
        }
        while (!q.empty()) {
            node *now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (now->next[i] != nullptr) {
                    now->next[i]->nex = now->nex->next[i];
                    now->next[i]->val = min(now->next[i]->val, now->nex->next[i]->val);
                    q.push(now->next[i]);
                } else now->next[i] = now->nex->next[i];
            }
        }
    }

    void qry1(const string &s) {
        node *now = root;
        for (int i = 0; i < s.length(); i++) {
            now = now->next[s[i] - 'a'];
            rx[i] = max(rx[i], i - now->val + 1);
        }
    }

    void qry2(const string &s) {
        node *now = root;
        for (int i = 0; i < s.length(); i++) {
            now = now->next[s[i] - 'a'];
            int idx = s.length() - 1 - i;
            lx[idx] = min(lx[idx], idx + now->val - 1);
        }
    }
} t;

struct Ftree {
private:
    vi t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v) {
        while (i < t.size()) {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i) {
        int s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r) {
        return qry1(r) - qry1(l - 1);
    }
} tx;

int c1, c2;
string s1[N], s2[N], s;
vi have[N];

inline void Zlin() {
    cin >> c1 >> c2;
    for (int i = 0; i < c1; i++) cin >> s1[i];
    for (int i = 0; i < c2; i++) cin >> s2[i];
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        lx[i] = 1e7;
        rx[i] = -1;
    }
    t.init();
    for (int i = 0; i < c2; i++) t.ins(s2[i], s2[i].size());
    t.build();
    t.qry1(s);
    t.init();
    for (int i = 0; i < c1; i++) {
        reverse(s1[i].begin(), s1[i].end());
        t.ins(s1[i], s1[i].size());
    }
    t.build();
    reverse(s.begin(), s.end());
    t.qry2(s);
    for (int i = 0; i < s.length(); i++) have[i].clear();
    for (int i = 0; i < s.length(); i++) if (rx[i] >= 0) have[rx[i]].emplace_back(i);
    ll ans = 0;
    tx.init(s.length() + 2);
    for (int i = s.length() - 1; ~i; i--) {
        for (int pos: have[i]) tx.upd(pos + 1, 1);
        if (lx[i] < s.length()) ans += tx.qry2(lx[i] + 1, s.length());
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
