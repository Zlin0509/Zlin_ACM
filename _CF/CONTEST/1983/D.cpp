//
// Created by Zlin on 2024/9/3.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

#define lowbit(x) (x&(-x))

const int N = 1e5 + 5;

int t1[100010], t2[100010];

inline void add(int i, int n, int *t) {
    for (; i <= n; i += lowbit(i))
        ++t[i];
}

inline int query(int l, int r, int *t) {
    int ans = 0;
    for (; r; r -= lowbit(r)) ans += t[r];
    --l;
    for (; l; l -= lowbit(l)) ans += t[l];
    return ans;
}

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c;
    for (int i = 1; i <= n; i++) cin >> a[i], c.push_back(a[i]);
    for (int i = 1; i <= n; i++) cin >> b[i], c.push_back(b[i]);

    sort(c.begin(), c.end());
    int len = unique(c.begin(), c.end()) - c.begin();
    if (len != n) {
        cout << "NO\n";
        return;
    }
    map<int, int> d;
    for (int i = 0; i < len; i++) {
        d[c[i]] = i + 1;
    }
    for (int i = 1; i <= len; i++) t1[i] = t2[i] = 0;
    ll c1 = 0, c2 = 0;
    for (int i = n; i >= 1; i--) {
        c1 += query(1, d[a[i]], t1);
        c2 += query(1, d[b[i]], t2);
        add(d[a[i]], len, t1);
        add(d[b[i]], len, t2);
    }
    cout << (c1 % 2 == c2 % 2 ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}