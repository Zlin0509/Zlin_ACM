//
// Created by Zlin on 2024/9/9.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 5e5 + 5;
int n, m, k;
int p[N][33], pos[N][33];

inline void insert(int x, int id) {
    int t = id;
    for (int i = 30; ~i; i--) {
        p[id][i] = p[id - 1][i];
        pos[id][i] = pos[id - 1][i];
    }
    for (int i = 30; ~i; i--) {
        if (!(x & (1 << i))) continue;
        if (!p[id][i]) {
            p[id][i] = x;
            pos[id][i] = t;
            return;
        } else if (pos[id][i] < t) {
            swap(p[id][i], x);
            swap(pos[id][i], t);
        }
        x ^= p[id][i];
    }
}

inline void Zlin() {
    memset(p, 0, sizeof p);
    memset(pos, 0, sizeof pos);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        insert(x, i);
    }
    int x, l, r, last = 0;
    while (m--) {
        cin >> x;
        if (x) {
            cin >> l;
            insert(l ^ last, ++n);
        } else {
            cin >> l >> r;
            l = (l ^ last) % n + 1;
            r = (r ^ last) % n + 1;
            if (l > r) swap(l, r);
            int ans = 0;
            for (int i = 30; ~i; i--)
                if ((ans ^ p[r][i]) > ans && pos[r][i] >= l)
                    ans ^= p[r][i];
            cout << ans << '\n';
            last = ans;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}