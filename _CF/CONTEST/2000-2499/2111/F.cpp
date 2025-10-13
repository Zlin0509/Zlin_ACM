//
// Created by 27682 on 2025/10/13.
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

constexpr int N = 5e4;

int pre[N + 5]{};

inline void Zlin() {
    int p, s;
    cin >> p >> s;
    for (int sx = 1, px, lx, rx; sx <= N; sx++) {
        if (p * sx % s) continue;
        lx = pre[sx];
        rx = sx / 4 * 8 + 2 + 2 * (sx % 4);
        px = p * sx / s;
        // if (sx == 16) {
        //     cout << lx << ' ' << rx << endl;
        // }
        if (lx > px || rx < px || px & 1) continue;
        for (int x = 1; x <= sx; x++) {
            for (int y = 1; x * y <= sx; y++) {
                int tmp = sx - x * y, res = (px - (x + y) * 2) / 2;
                if (res < min(1, tmp) * 2 || tmp < res || tmp - res + 1 > y) continue;
                cout << sx << endl;
                for (int i = 1; i <= x; i++) for (int j = 1; j <= y; j++) cout << i << ' ' << j << endl;
                for (int i = x + 1; res; i++, res--) {
                    if (!tmp) break;
                    cout << i << ' ' << 1 << endl;
                    --tmp;
                }
                for (int j = 2; tmp; j++, tmp--) cout << x + 1 << ' ' << j << endl;
                return;
            }
        }
        cout << px << ' ' << sx << endl;
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * i <= N; j++) {
            if (!pre[i * j]) pre[i * j] = (i + j) * 2;
            else pre[i * j] = min(pre[i * j], (i + j) * 2);
        }
    }
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
