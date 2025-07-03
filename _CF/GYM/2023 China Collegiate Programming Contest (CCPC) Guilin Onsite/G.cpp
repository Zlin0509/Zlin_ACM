//
// Created by 27682 on 2025/7/2.
//
#include <bits/stdc++.h>
using namespace std;

inline void Zlin() {
    string s, ans;
    cin >> s;
    int cnt = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') ++cnt;
        else {
            --cnt;
            if (cnt < 0) {
                cout << "impossible" << endl;
                return;
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            while (cnt1 && cnt2) {
                ans += ')';
                --cnt1, --cnt2;
            }
            ans += '(';
            ++cnt1;
        } else {
            if (cnt1 > cnt2) {
                ++cnt2;
            } else {
                while (cnt1 && cnt2) {
                    ans += ')';
                    --cnt1;
                    --cnt2;
                }
                ans += ')';
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
