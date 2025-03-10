//
// Created by Zlin on 2024/10/22.
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

const int N = 2e5 + 5;
const int NN = 1e6 + 1;

int n, q, len, check;
int a[N];
bool ans[N];
int cnt[NN];
struct Query {
    int l, r, id;
} c[N];

int get(int x) {
    return x / len;
}

bool cmp(const Query &a, const Query &b) {
    int la = get(a.l), lb = get(b.l);
    if (la != lb) return la < lb;
    return (la & 1) ? (a.r < b.r) : (a.r > b.r);  // 奇偶区块不同方向优化
}

void add(int x) {
    cnt[a[x]]++;
    cnt[a[x]] & 1 ? ++check : --check;
}

void del(int x) {
    cnt[a[x]]--;
    cnt[a[x]] & 1 ? ++check : --check;
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        cin >> c[i].l >> c[i].r;
        c[i].id = i;
    }
    len = sqrt(n) + 1;
    check = 0;
    sort(c + 1, c + 1 + q, cmp);
    for (int i = 1, l = 1, r = 0; i <= q; i++) {
        while (r < c[i].r) add(++r);
        while (r > c[i].r) del(r--);
        while (l < c[i].l) del(l++);
        while (l > c[i].l) add(--l);
        ans[c[i].id] = !check;
//        cout << check << " ";
    }
    for (int i = 1; i <= q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
    for (int i = 0; i <= n; i++) cnt[a[i]] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}