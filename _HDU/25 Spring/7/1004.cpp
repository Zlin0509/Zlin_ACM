//
// Created by 27682 on 2025/4/18.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.length() - 1;
    set<int> len[2], pos[2][n + 1];
    vi llen(n + 1);
    int lx = 1;
    for (int i = 1; i <= n; i++) {
        if (s[lx] == s[i]) continue;
        len[s[lx] - '0'].insert(i - lx);
        pos[s[lx] - '0'][i - lx].insert(lx);
        llen[lx] = i - lx;
    }
    len[s[lx] - '0'].insert(n + 1 - lx);
    pos[s[lx] - '0'][n + 1 - lx].insert(lx);
    llen[lx] = n + 1 - lx;
    int q;
    cin >> q;
    while (q--) {
        int op, k;
        cin >> op >> k;
        if (len[op].lower_bound(k) == len[op].end()) {
            cout << -1 << endl;
        } else {
            int l = *len[op].lower_bound(k), rx;
            int id = *pos[op][l].begin();
            llen[id] = 0;
            pos[op][l].erase(pos[op][l].begin());
            if (pos[op][l].empty()) len[op].erase(l);

            if (l == k) {
                if (id + l > n) continue;
                int lx = llen[id + l];

            } else {
                llen[id + k] = l - k;
                len[op].insert(l - k);
                pos[op][l - k].insert(id + k);
                rx = id + k - 1;
            }
        }
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
