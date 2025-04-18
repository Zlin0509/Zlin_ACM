//
// Created by Zlin on 2025/1/16.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

vi e[100010];
int n;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    for (int i = 1, k, v; i <= n; i++) {
        cin >> k;
        while (k--) {
            cin >> v;
            e[i].push_back(v);
        }
    }
    int x, y, now = 1;
    vi ans;
    unordered_map<int, int> mp;
    while (m--) {
        cin >> x >> y;
        if (x == 0) {
            now = e[now][y - 1];
        } else if (x == 1) {
            mp[y] = now;
            ans.push_back(now);
        } else {
            now = mp[y];
        }
    }
    for(auto it: ans) cout << it << endl;
    cout << now;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
