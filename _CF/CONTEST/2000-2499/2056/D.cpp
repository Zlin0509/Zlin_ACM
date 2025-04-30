//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 1ll * n * (n + 1) / 2;
    for (int i = 1; i <= 10; i++) {
        vi b(n + 1), nxt(n + 1);
        int lx = 0;
        for (int j = 1; j <= n; j++) {
            b[j] = a[j] <= i ? 1 : 0;
            b[j] += b[j - 1];
            if (a[j] == i) lx = j;
            nxt[j] = lx - 1;
        }
        int tag = 0;
        unordered_map<int, int> buf[2];
        for (int j = 1; j <= n; j++) {
            while (tag <= nxt[j]) {
                buf[0][2 * b[tag] - tag]++;
                buf[1][2 * b[tag] - tag]++;
                ++tag;
            }
            ans -= buf[j & 1][2 * b[j] - j];
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
