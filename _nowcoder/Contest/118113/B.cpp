//
// Created by 27682 on 2025/9/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    string s;
    cin >> s;
    int n = s.length();
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            if (s[i + 1] >= '5') {
                string tmp = ans;
                ans.clear();
                int tag = 1;
                while (!tmp.empty()) {
                    char c = tmp.back();
                    tmp.pop_back();
                    if (tag) {
                        if (c != '9') {
                            ++c;
                            tag = 0;
                        } else {
                            c = '0';
                            tag = 1;
                        }
                    }
                    ans += c;
                }
                if (tag) ans += '1';
                reverse(ans.begin(), ans.end());
            }
            break;
        }
        ans += s[i];
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
