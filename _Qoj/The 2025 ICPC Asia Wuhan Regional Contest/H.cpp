//
// Created by Zlin on 2025/11/7.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<int, int> mp;

int n, fac2[33];
set<int> ans;

inline void dfs(int pre, int ask, int i) {
    if (ans.size() == n) return;
    int tmp, val;
    if (mp[ask]) tmp = mp[ask];
    else {
        cout << "? " << ask << endl;
        cin >> tmp;
        mp[ask] = tmp;
    }
    for (int j = i - 1; ~j; j--) {
        if (ask >> j & 1) {
            dfs(pre, ask - (1 << i), j);
            break;
        }
    }
    if (tmp >> i & 1 && i) {
        val = pre / fac2[i] * fac2[i] - fac2[i] + (tmp ^ ask) % fac2[i];
        ans.insert(val);
        int ask1 = ask / fac2[i] * fac2[i] + val % fac2[i];
        for (int j = i - 1; ~j; j--) {
            if (val >> j & 1) {
                dfs(val, ask1, j);
                break;
            }
        }
    }
    if (tmp % fac2[i] == 0) return;
    val = pre / fac2[i] * fac2[i] + (tmp ^ ask) % fac2[i];
    ans.insert(val);
}

inline void Zlin() {
    mp.clear();
    ans.clear();
    cin >> n;
    cout << "? 0" << endl;
    int tmp;
    cin >> tmp;
    ans.insert(tmp);
    mp[0] = tmp;
    for (int i = 30; ~i; i--)
        if (tmp >> i & 1) {
            dfs(tmp, tmp, i);
            break;
        }
    cout << "! ";
    for (const auto it: ans) cout << it << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    fac2[0] = 1;
    for (int i = 1; i < 32; i++) fac2[i] = fac2[i - 1] * 2;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
