//
// Created by Zlin on 2024/10/16.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e6;

struct Query {
    int qid, l, r, cid;
} q[N];

struct Change {
    int p, x;
} c[N];

int cntq = 0, cntc = 0;

int n, m, len, res = 0;
int w[N], cnt[N], ans[N];

int get(int i) {
    return i / len;
}

void add(int i) {
    if (!cnt[i]) ++res;
    ++cnt[i];
}

void del(int i) {
    --cnt[i];
    if (!cnt[i]) --res;
}

bool cmp(const Query &a, const Query &b) {
    int la = get(a.l), ra = get(a.r);
    int lb = get(b.l), rb = get(b.r);
    if (la != lb) return la < lb;
    if (ra != rb) return ra < rb;
    return a.cid < b.cid;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (op == 'Q') ++cntq, q[cntq] = {cntq, l, r, cntc};
        else c[++cntc] = {l, r};
    }
    len = cbrt((double)n * max(1, cntc)) + 1;
    sort(q + 1, q + cntq + 1, cmp);
    res = 0;
    for (int i = 1, l = 0, r = 0, cid = 0; i <= cntq; i++) {
        while (r < q[i].r) add(w[++r]);
        while (r > q[i].r) del(w[r--]);
        while (l < q[i].l) del(w[l++]);
        while (l > q[i].l) add(w[--l]);
        while (cid < q[i].cid) {
            ++cid;
            if (c[cid].p >= q[i].l && c[cid].p <= q[i].r) {
                del(w[c[cid].p]);
                add(c[cid].x);
            }
            swap(w[c[cid].p], c[cid].x);
        }
        while (cid > q[i].cid) {
            if (c[cid].p >= q[i].l && c[cid].p <= q[i].r) {
                del(w[c[cid].p]);
                add(c[cid].x);
            }
            swap(w[c[cid].p], c[cid].x);
            --cid;
        }
        ans[q[i].qid] = res;
    }
    for (int i = 1; i <= cntq; i++)
        cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}