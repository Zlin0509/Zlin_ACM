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

const int N = 6e5;

struct Query {
    int id, l, r;
} q[N];

int n, m, len;
ll B[N], ans[N], resa = 0, resb = 0, cnt = 0, sum = 0;
vi up[N];

int get(int i) { return i / len; }

bool cmp(const Query &a, const Query &b) {
    int la = get(a.l), ra = get(a.r);
    int lb = get(b.l), rb = get(b.r);
    if (la != lb) return la < lb;
    if (ra != rb) return ra < rb;
    return a.l < b.l;
}

void add_l(int l, int r) {
    resa += 2 * sum + cnt;
    sum += cnt;
    resb += B[l];
    for (auto i: up[l]) {
        if (i > r) break;
        resb -= B[i];
        resa += (i - l + 1) * (i - l + 1) * 1ll;
        cnt++;
        sum += i - l + 1;
    }
}

void del_l(int l, int r) {
    for (auto i: up[l]) {
        if (i > r) break;
        resb += B[i];
        resa -= (i - l + 1) * (i - l + 1) * 1ll;
        cnt--;
        sum -= i - l + 1;
    }
    resa -= 2 * sum - cnt;
    sum -= cnt;
    resb -= B[l];
}

void add_r(int l, int r) {
    int dif = r - l + 1;
    if (B[r] >= 1ll * dif * dif) resb += B[r];
    else {
        ++cnt;
        sum += dif;
        resa += 1ll * dif * dif;
    }
}

void del_r(int l, int r) {
    int dif = r - l + 1;
    if (B[r] >= 1ll * dif * dif) resb -= B[r];
    else {
        --cnt;
        sum -= dif;
        resa -= 1ll * dif * dif;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        up[max(0, i - (int) sqrt(B[i]))].push_back(i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    len = double(n / sqrt(m)) + 1;
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1, l = 0, r = 0; i <= m; i++) {
        while (r < q[i].r) add_r(l, ++r);
        while (r > q[i].r) del_r(l, r--);
        while (l < q[i].l) del_l(l++, r);
        while (l > q[i].l) add_l(--l, r);
        ans[q[i].id] = resa + resb;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}