//
// Created by Zlin on 2025/5/17.
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

int cnt[5];

inline void Zlin() {
    int k;
    string s;
    string tag = "lose";
    cin >> k >> s;
    for (int i = 0; i < s.size();) {
        int len = 0;
        for (int j = 0; j < tag.size(); j++) {
            for (int q = 0, dif = 0; j + q < tag.size() && i + dif < s.size(); q++) {
                if (s[i + dif] != tag[j + q]) continue;
                ++dif;
                len = max(len, dif);
            }
        }
        cnt[4 - len]++;
        len ? i += len : i++;
    }
    cnt[4] = 1e9;
    int ans = cnt[0];
    for (int i = 1, all; i <= 4; i++) {
        all = min(k / i, cnt[i]);
        ans += all;
        k -= all * i;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
