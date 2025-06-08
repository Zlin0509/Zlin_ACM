//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n), b(n);
    set<int> sa, sb;
    for (int &it: a) cin >> it;
    for (int &it: b) cin >> it;
    int ans = 0;
    for (int i = n - 1; ~i; i--) {
        if (i & 1) {
            if (i) {
                if (sa.find(b[i - 1]) != sa.end() || sb.find(a[i - 1]) != sb.end()) {
                    ans = max(ans, i);
                }
            }
            sa.insert(a[i]);
            sb.insert(b[i]);
            if (sa.find(b[i]) != sa.end() || sb.find(a[i]) != sb.end()) {
                ans = max(ans, i + 1);
            }
        } else {
            if (i) {
                if (sa.find(a[i - 1]) != sa.end() || sb.find(b[i - 1]) != sb.end()) {
                    ans = max(ans, i);
                }
            }
            sa.insert(b[i]);
            sb.insert(a[i]);
            if (sa.find(a[i]) != sa.end() || sb.find(b[i]) != sb.end()) {
                ans = max(ans, i + 1);
            }
        }
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
