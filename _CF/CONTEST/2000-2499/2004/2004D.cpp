//
// Created by Zlin on 2024/8/28.
//
#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9;
const string vars[] = {"BG", "BR", "BY", "GR", "GY", "RY"};

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char s[5];
        cin >> s;
        a[i] = find(vars, vars + 6, s) - vars;
    }
    vector<vector<int>> lf(n), rg(n);
    for (int o = 0; o < 2; ++o) {
        vector<int> last(6, -INF);
        for (int i = 0; i < n; ++i) {
            last[a[i]] = (o ? n - i - 1 : i);
            (o ? rg[n - i - 1] : lf[i]) = last;
        }
        reverse(a.begin(), a.end());
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int ans = INF;
        for (int j = 0; j < 6; ++j) {
            if (a[x] + j != 5 && j + a[y] != 5) {
                ans = min(ans, abs(x - lf[x][j]) + abs(lf[x][j] - y));
                ans = min(ans, abs(x - rg[x][j]) + abs(rg[x][j] - y));
            }
        }
        if (ans > INF / 2) ans = -1;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}