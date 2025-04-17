//
// Created by Zlin on 2025/1/16.
//

#include "bits/stdc++.h"

using namespace std;

inline void Zlin() {
    string tag = "chi1 huo3 guo1";
    int cnt = 0, beg = INT_MAX, num = 0;
    while (1) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        ++cnt;
        for (int i = 0; i < s.length(); i++) {
            bool check = true;
            for (int j = 0; j < tag.length(); j++) {
                if (i + j >= s.length() || s[i + j] != tag[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ++num;
                beg = min(beg, cnt);
                break;
            }
        }
        s.clear();
    }
    cout << cnt << endl;
    if (!num) {
        cout << "-_-#";
    } else {
        cout << beg << ' ' << num;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
