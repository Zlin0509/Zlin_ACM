//
// Created by Zlin on 2024/9/3.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

unordered_map<int, int> used;
priority_queue<int, vi, greater<int>> q;
const int N = 3e5 + 5;
const int inf = INT_MAX;
int a[N];
vi b[N];
struct tree {
    int l, r, mn = inf, mx = -inf;
} t[N << 2];

inline void build(int l, int r, int i) {
    t[i].l = l, t[i].r = r;
    if (l == r) {
        t[i].mx = t[i].mn = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, i << 1);
    build(mid + 1, r, i << 1 | 1);
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mn = min(t[i << 1].mn, t[i << 1 | 1].mn);
}

inline void change(int i, int k, int z) {
    int l = t[i].l, r = t[i].r, mid = l + r >> 1;
    if (l == r) {
        t[i].mx = t[i].mn = z;
        return;
    }
    if (mid >= k)change(i << 1, k, z);
    else change(i << 1 | 1, k, z);
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mn = min(t[i << 1].mn, t[i << 1 | 1].mn);
}

inline int query1(int l, int r, int i) {
    int ans = -inf;
    int ll = t[i].l, rr = t[i].r;
    if (ll > r || rr < l) return ans;
    if (l <= ll && rr <= r) return t[i].mx;
    ans = max(ans, query1(l, r, i << 1));
    ans = max(ans, query1(l, r, i << 1 | 1));
    return ans;
}

inline int query2(int l, int r, int i) {
    int ans = inf;
    int ll = t[i].l, rr = t[i].r;
    if (ll > r || rr < l) return ans;
    if (l <= ll && rr <= r)return t[i].mn;
    ans = min(ans, query2(l, r, i << 1));
    ans = min(ans, query2(l, r, i << 1 | 1));
    return ans;
}

inline void reset(int i, int k) {
    if (t[i].l == t[i].r) {
        t[i].mn = inf;
        t[i].mx = -inf;
        return;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (mid >= k) reset(i << 1, k);
    else reset(i << 1 | 1, k);
    t[i].mx = max(t[i << 1].mx, t[i << 1 | 1].mx);
    t[i].mn = min(t[i << 1].mn, t[i << 1 | 1].mn);
}

inline void Zlin() {
    used.clear();
    int n, cnt = 0;
    vi ans;
    cin >> n;
    for (int i = 1; i <= n; i++) b[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]].push_back(i);
    for (int i = n; i >= 1; i--)
        if (!used[a[i]]) ++used[a[i]], ++cnt, q.push(i);
    build(1, n, 1);
    int l = 1, r = q.top(), k;
    q.pop();
    while (ans.size() < cnt) {
        ans.size() & 1 ? k = query2(l, r, 1) : k = query1(l, r, 1);
        ans.push_back(k);
        --used[k];
        for (auto it: b[k]) reset(1, it), a[it] = -1;
        l = *lower_bound(b[k].begin(), b[k].end(), l) + 1;
        while (a[r] == -1 && !q.empty()) {
            r = q.top();
            q.pop();
        }
    }
    cout << ans.size() << '\n';
    for (auto it: ans) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}