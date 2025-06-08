//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int getk(vi &a) {
    int n = a.size(), res = 0;
    map<int, int> mp;
    for (int it: a) mp[it]++;
    vector<pii> top(mp.begin(), mp.end());
    sort(top.begin(), top.end(), [](auto &x, auto &y) { return x.second > y.second; });
    for (int i = 0; i < min(5, (int) top.size()); i++) {
        int v = top[i].first;
        vi pre(n + 1);
        for (int j = 0; j < n; j++) pre[j + 1] = pre[j] + (a[j] == v);
        for (int l = 0; l < n; l++) {
            for (int r = l; r < min(n, l + 1000); ++r) {
                int len = r - l + 1;
                int cnt = pre[r + 1] - pre[l];
                int need = (len + 1) / 2;
                if (cnt >= need) res = max(res, cnt - need);
            }
        }
    }
    return res;
}

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int &it: a) cin >> it;
    while (q--) {
        int i, x;
        cin >> i >> x;
        a[i - 1] = x;
        cout << getk(a) << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) Zlin();
    return 0;
}
