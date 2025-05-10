//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 52;

int n, m, cnt = 0;
vi res;
vector<vi> ans;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        res.push_back(u);
        res.push_back(v);
        for (int j = 1; j <= n; j++) {
            if (j == u || j == v) continue;
            res.push_back(j);
        }
        ans.push_back(res);
        res.clear();

        for (int j = n; j; j--) {
            if (j == u || j == v) continue;
            res.push_back(j);
        }
        res.push_back(u);
        res.push_back(v);
        ans.push_back(res);
        res.clear();
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (vi &it: ans) {
        for (int x: it) {
            cout << x << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
