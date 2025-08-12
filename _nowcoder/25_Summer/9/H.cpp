//
// Created by Zlin on 2025/8/12.
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

constexpr int N = 2e5 + 7;

int idx[3005]; //当前年之前的所有天数
int m1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pre1[15];
int pre2[15];

inline void pre() {
    int cnt = 0;
    for (int y = 2000; y <= 2999; y++) {
        idx[y] = cnt;
        for (int m = 1; m <= 12; m++) {
            for (int d = 1; d <= 31; d++) {
                if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
                } else if (m == 2) {
                    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
                        if (d > 29) break;
                    } else {
                        if (d > 28) break;
                    }
                } else {
                    if (d > 30) break;
                }
                ++cnt;
            }
        }
    }
    for (int i = 1; i <= 12; i++) {
        pre1[i] = pre1[i - 1] + m1[i - 1];
        pre2[i] = pre2[i - 1] + m2[i - 1];
    }
}

int n, vis[N << 4], dp[N << 4];

inline void Zlin() {
    cin >> n;
    vector<pii> v;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int yea = stoi(s1.substr(0, 4));
        int mon = stoi(s1.substr(5, 2));
        int day = stoi(s1.substr(8, 2));
        int xs = stoi(s2.substr(0, 2));
        int cnt;
        if (yea % 400 == 0 || (yea % 4 == 0 && yea % 100 != 0)) cnt = idx[yea] + pre2[mon] + day;
        else cnt = idx[yea] + pre1[mon] + day;
        int l = cnt, r = cnt;
        if (xs >= 18) r = cnt + 1;
        if (xs < 20) l = cnt - 1;
        l = max(1, l), r = min(r, idx[2999] + 365);
        v.emplace_back(l, r);
    }
    sort(v.begin(), v.end());
    for (auto [l, r]: v) {
        for (int i = r; i >= l; i--) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
    }
    int ans = 0;
    for (auto [l, r]: v) {
        for (int i = l; i <= r; i++) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << ' ' << 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    pre();
    while (ttt--) Zlin();
    return 0;
}
