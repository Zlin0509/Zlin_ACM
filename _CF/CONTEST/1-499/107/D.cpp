//
// Created by 27682 on 2025/7/16.
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

constexpr ll mo = 12345;
constexpr int N = 150;

ll n, c, a[N][N], f[N], tmp[N][N];
int mul[26], op = 1;
vi have[26];

inline void mul1() {
    for (int i = 0; i < op; i++) {
        for (int j = 0; j < op; j++) {
            for (int k = 0; k < op; k++) {
                tmp[i][j] = (tmp[i][j] + a[i][k] * a[k][j]) % mo;
            }
        }
    }
    for (int i = 0; i < op; i++)
        for (int j = 0; j < op; j++)
            a[i][j] = tmp[i][j], tmp[i][j] = 0;
}

inline void mul2() {
    for (int j = 0; j < op; j++)
        for (int k = 0; k < op; k++)
            tmp[0][j] = (tmp[0][j] + f[k] * a[k][j]) % mo;
    for (int i = 0; i < op; i++)
        f[i] = tmp[0][i], tmp[0][i] = 0;
}

inline void Zlin() {
    cin >> n >> c;
    for (int i = 1, id, val; i <= c; i++) {
        char c;
        cin >> c >> val;
        id = c - 'A';
        have[id].emplace_back(val);
        if (!mul[id]) mul[id] = 1;
        op *= val, mul[id] *= val;
    }
    ++op;
    for (int z = 0; z < op; z++) {
        int now = z, mult = 1;
        for (int i = 25; ~i; i--) {
            if (!mul[i]) continue;
            int cnt = now % mul[i];
            int s = z - cnt * mult;
            cnt = (cnt + 1) % mul[i];
            s += cnt * mult;
            ++a[s][z];
            now /= mul[i];
            mult *= mul[i];
        }
    }
    f[0] = 1;
    while (n) {
        if (n & 1) mul2();
        mul1();
        n >>= 1;
    }
    ll ans = 0;
    for (int z = 0; z < op; z++) {
        bool check = true;
        int now = z;
        for (int i = 25; ~i; i--) {
            if (!mul[i]) continue;
            int cnt = now % mul[i];
            bool tag = false;
            for (int it: have[i]) tag |= cnt % it == 0;
            check &= tag;
            now /= mul[i];
        }
        if (check) ans = (ans + f[z]) % mo;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
