//
// Created by Zlin on 2025/11/3.
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

constexpr int N = 202;

int n, m, a[N][N], b[N][N], lst[N];
vector<string> ans;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c == 'B';
        }
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
        lst[i] = 0;
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j];
            if (b[i][j]) lst[i] = j;
        }
    }
    for (int k = 0; k < n; k++) {
        string tmp;
        while (lst[k] && ans.size() < 400) {
            tmp.clear();
            int stk = 0;
            for (int i = 0; i < n; i++) {
                while (stk < lst[i]) {
                    tmp += 'R';
                    ++stk;
                }
                if (i != n - 1) tmp += 'D';
            }
            while (stk != m - 1) {
                ++stk;
                tmp += 'R';
            }
            int x = 0, y = 0;
            for (const auto &c: tmp) {
                b[x][y] ^= 1;
                if (c == 'R') ++y;
                if (c == 'D') ++x;
            }
            b[x][y] ^= 1;
            for (int i = k; i < n; i++) {
                lst[i] = 0;
                for (int j = 0; j < m; j++) if (b[i][j]) lst[i] = j;
            }
            ans.emplace_back(tmp);
        }
    }
    bool check = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j]) {
                check = false;
                break;
            }
        }
    }
    if (check) {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (const auto &it: ans) cout << it << endl;
        return;
    }
    ans.clear();
    for (int i = 0; i < n; i++) {
        lst[i] = 0;
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j] ^ 1;
            if (b[i][j]) lst[i] = j;
        }
    }
    for (int k = 0; k < n; k++) {
        string tmp;
        while (lst[k] && ans.size() < 400) {
            tmp.clear();
            int stk = 0;
            for (int i = 0; i < n; i++) {
                while (stk < lst[i]) {
                    tmp += 'R';
                    ++stk;
                }
                if (i != n - 1) tmp += 'D';
            }
            while (stk != m - 1) {
                ++stk;
                tmp += 'R';
            }
            int x = 0, y = 0;
            for (const auto &c: tmp) {
                b[x][y] ^= 1;
                if (c == 'R') ++y;
                if (c == 'D') ++x;
            }
            b[x][y] ^= 1;
            for (int i = k; i < n; i++) {
                lst[i] = 0;
                for (int j = 1; j < m; j++) if (b[i][j]) lst[i] = j;
            }
            ans.emplace_back(tmp);
        }
    }
    check = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j]) {
                check = false;
                break;
            }
        }
    }
    if (check) {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (const auto &it: ans) cout << it << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
