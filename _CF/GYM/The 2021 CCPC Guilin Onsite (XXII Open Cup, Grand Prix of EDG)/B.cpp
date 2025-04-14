//
// Created by Zlin on 2025/4/13.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vi a(n + 1), b(n + 1), s(n + 2);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        b[i] = c - '0';
    }
    for (int i = n; ~i; i--) {
        s[i] = a[i] + b[i] + s[i + 1] % 10;
    }
    set<int> sr[2];
    int sl[n + 1];
    for (int i = n - 1, lst = n; ~i; i--) {
        if (s[i] % 10 == s[i + 1] % 10) continue;
        if (s[lst] % 10 == 0) sr[0].insert(lst), sl[lst] = i + 1;
        if (s[lst] % 10 == 9) sr[1].insert(lst), sl[lst] = i + 1;
        lst = i;
    }

    auto check = [&](int x) {
        if (sr[0].lower_bound(x) != sr[0].end() && sl[*sr[0].lower_bound(x)] <= x)
            return 0;
        if (sr[1].lower_bound(x) != sr[1].end() && sl[*sr[1].lower_bound(x)] <= x)
            return 1;
        return -1;
    };

    auto cal1 = [&](int c, int tag) {
        int rx, lx;
        if (tag % 10 == 9) {
            rx = *sr[1].lower_bound(c);
            lx = sl[rx];
            sr[1].erase(sr[1].find(rx));
            if (rx != c) {
                sr[1].insert(rx);
                sl[rx] = c + 1;
            }
            if (lx != c) {
                sr[1].insert(c - 1);
                sl[c - 1] = lx;
            }
        }
        if (tag % 10 == 0) {
            rx = *sr[0].lower_bound(c);
            lx = sl[rx];
            sr[0].erase(sr[0].find(rx));
            if (rx != c) {
                sr[0].insert(rx);
                sl[rx] = c + 1;
            }
            if (lx != c) {
                sr[0].insert(c - 1);
                sl[c - 1] = lx;
            }
        }
    };
    auto cal2 = [&](int c, int ans1) {
        int rx, lx;
        if (ans1 % 10 == 9) {
            lx = rx = c;
            if (sr[1].find(c - 1) != sr[1].end()) {
                sr[1].erase(sr[1].find(c - 1));
                lx = sl[c - 1];
            }
            if (sr[1].lower_bound(c) != sr[1].end() && sl[*sr[1].lower_bound(c)] == c + 1) {
                rx = *sr[1].lower_bound(c);
                sr[1].erase(sr[1].find(rx));
            }
            sr[1].insert(rx);
            sl[rx] = lx;
        }
        if (ans1 % 10 == 0) {
            lx = rx = c;
            if (sr[0].find(c - 1) != sr[0].end()) {
                sr[0].erase(sr[0].find(c - 1));
                lx = sl[c - 1];
            }
            if (sr[0].lower_bound(c) != sr[0].end() && sl[*sr[0].lower_bound(c)] == c + 1) {
                rx = *sr[0].lower_bound(c);
                sr[0].erase(sr[0].find(rx));
            }
            sr[0].insert(rx);
            sl[rx] = lx;
        }
    };
    while (q--) {
        int r, c, d, tag, ans1, ans2 = 1, lx, rx;
        cin >> r >> c >> d;
        tag = a[c] + b[c];
        r == 1 ? a[c] = d : b[c] = d;
        ans1 = a[c] + b[c];

        if (tag != ans1) {
            cal1(c, tag);
            if (tag % 10 != ans1 % 10) ++ans2;
            if (tag >= 10 && ans1 < 10) {
                if (check(c - 1) == 0) {
                    rx = *sr[0].lower_bound(c - 1);
                    lx = sl[rx];
                    sr[0].erase(sr[0].find(rx));
                    sr[1].insert(rx);

                    ans2 += rx - lx + 1;
                    if (lx != 1) ++ans2;
                } else if (check(c - 1) == 1) {
                    rx = *sr[1].lower_bound(c - 1);
                    lx = sl[rx];
                    sr[1].erase(sr[1].find(rx));
                    sr[1].insert(rx - 1);
                    sl[rx - 1] = lx;
                    ++ans2;
                } else if ((a[c - 1] + b[c - 1]) % 10 == 1) {
                    cal2(c - 1, 0);
                    ++ans2;
                } else ++ans2;
            } else if (tag < 10 && ans1 >= 10) {
            }
            cal2(c, ans1);
        }

        cout << ans1 % 10 << ' ' << ans2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
