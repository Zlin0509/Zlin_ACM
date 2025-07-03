//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int n, m, k;
vi a, b;

multiset<int> need;

inline void Zlin() {
    cin >> n >> m >> k;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end(), greater());
    ll ans = 0;
    for (int i = 0; i < m * k; i++) need.insert(b[i]), ans += b[i];
    int cnt = 0;
    vi pos;
    for (int i = 0; i < n; i++) {
        if (need.find(a[i]) != need.end()) ++cnt, need.erase(need.find(a[i]));
        if (cnt == m) pos.push_back(i + 1), cnt = 0;
    }
    cout << ans << endl;
    for (int i = 0; i < k - 1; i++) cout << pos[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
