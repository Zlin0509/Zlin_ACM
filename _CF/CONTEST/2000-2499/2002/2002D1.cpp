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

const int N = 1 << 16;

int n, q, m, cnt;
int p[N], place[N], dep[N];
bool vec[N];

bool check(int x) {
    if (dep[x] == m) return 1;
    if (place[x] + 1 > n || place[x] + (1 << (m - dep[x])) > n) return 0;
    if (p[place[x] + 1] / 2 != x || p[place[x] + (1 << (m - dep[x]))] / 2 != x) return 0;
    return 1;
}

void init() {
    dep[1] = 1;
    cnt = 0;
    for (int i = 1; i <= n; i++) vec[i] = 0;
}

inline void Zlin() {
    cin >> n >> q;
    init();
    for (int i = 2, x; i <= n; i++) cin >> x, dep[i] = dep[i / 2] + 1;
    for (int i = 1; i <= n; i++) cin >> p[i], place[p[i]] = i;
    m = dep[n];
    for (int i = 1; i <= n; i++)
        if (!check(i)) ++cnt, vec[i] = 1;
    int x, y;
    while (q--) {
        cin >> x >> y;
        swap(p[x], p[y]);
        swap(place[p[x]], place[p[y]]);
        if (dep[p[x]] < m) {
            if (check(p[x])) {
                if (vec[p[x]]) --cnt;
                vec[p[x]] = 0;
            } else {
                if (!vec[p[x]]) ++cnt;
                vec[p[x]] = 1;
            }
        }
        if (dep[p[y]] < m) {
            if (check(p[y])) {
                if (vec[p[y]]) --cnt;
                vec[p[y]] = 0;
            } else {
                if (!vec[p[y]]) ++cnt;
                vec[p[y]] = 1;
            }
        }
        if (p[x] != 1) {
            if (check(p[x] / 2)) {
                if (vec[p[x] / 2]) --cnt;
                vec[p[x] / 2] = 0;
            } else {
                if (!vec[p[x] / 2])++cnt;
                vec[p[x] / 2] = 1;
            }
        }
        if (p[y] != 1) {
            if (check(p[y] / 2)) {
                if (vec[p[y] / 2]) --cnt;
                vec[p[y] / 2] = 0;
            } else {
                if (!vec[p[y] / 2])++cnt;
                vec[p[y] / 2] = 1;
            }
        }
        cout << (!cnt ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}