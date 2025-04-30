//
// Created by 27682 on 2025/3/30.
//
#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
constexpr double pi = 3.14159265358979323846;

inline void Zlin(long long n, long long k) {
    // long long n, k;
    // cin >> n >> k;
    vector<int> vis(n + 1);
    vector<int> f, g, z;
    for (int i = 1; i <= n; i++)
        f.push_back(i);
    while (f.size() > 1) {
        for (int i = 0; i < f.size(); i++) {
            if (i % k == 0) {
                vis[f[i]] = 1;
            } else {
                g.push_back(f[i]);
            }
        }
        f = g;
        g.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    cout << f[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    Zlin(40, 4);
    // while (ttt--) Zlin();
}
