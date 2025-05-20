//
// Created by 27682 on 2025/5/20.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int long long
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;

int f[N], nxt[N];

inline void Zlin() {
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    int base = x % y, k = x / y;
    s -= base * n;
    if (s < 0 || s % y) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= s; i++) f[i] = 2e9, nxt[i] = 0;
    for (int i = 1; i <= s; i++) {
        if (i % y) continue;
        for (int j = 1; ; j++) {
            int id = j * (j - 1) / 2 * y;
            if (id > i) break;
            if (f[i] > f[i - id] + j) {
                f[i] = f[i - id] + j;
                nxt[i] = j;
            }
        }
    }
    for (int j = 1; ; j++) {
        int id = (k * 2 + j - 1) * j / 2 * y;
        if (id > s) break;
        if (f[s - id] + j <= n) {
            cout << "YES" << endl;
            for (int i = 0; i < j; i++) cout << base + (k + i) * y << ' ';
            int tmp = n - j, now = s - id;
            while (now) {
                int dif = nxt[now];
                for (int i = 0; i < dif; i++) cout << base + i * y << ' ';
                tmp -= dif;
                now -= dif * (dif - 1) / 2 * y;
            }
            while (tmp--) cout << base << ' ';
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
