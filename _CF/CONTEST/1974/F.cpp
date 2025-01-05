//
// Created by Zlin on 2024/9/5.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int N = 2e5 + 5;
int a, b, n, mm;
int vis[N];
vector<pii> ux, uy;

inline void Zlin() {
    ux.clear(), uy.clear();
    cin >> a >> b >> n >> mm;
    ux.push_back({-100, 0});
    uy.push_back({-100, 0});
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        ux.push_back({x, i});
        uy.push_back({y, i});
        vis[i] = 0;
    }
    sort(ux.begin(), ux.end());
    sort(uy.begin(), uy.end());
    int lx = 0, rx = a + 1, ly = 0, ry = b + 1;
    int llx = 1, rrx = n, lly = 1, rry = n;
    int ans[2]{}, k;
    char c;
    for (int m = 0; m < mm; m++) {
        cin >> c >> k;
        if (c == 'U') {
            lx += k;
            while (ux[llx].first <= lx && llx <= n) {
                if (!vis[ux[llx].second]) ++ans[m & 1];
                vis[ux[llx].second] = 1;
                ++llx;
            }
        } else if (c == 'D') {
            rx -= k;
            while (ux[rrx].first >= rx && rrx >= 1) {
                if (!vis[ux[rrx].second]) ++ans[m & 1];
                vis[ux[rrx].second] = 1;
                --rrx;
            }
        } else if (c == 'L') {
            ly += k;
            while (uy[lly].first <= ly && lly <= n) {
                if (!vis[uy[lly].second]) ++ans[m & 1];
                vis[uy[lly].second] = 1;
                ++lly;
            }
        } else {
            ry -= k;
            while (uy[rry].first >= ry && rry >= 1) {
                if (!vis[uy[rry].second]) ++ans[m & 1];
                vis[uy[rry].second] = 1;
                --rry;
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}