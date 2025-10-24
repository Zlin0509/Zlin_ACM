//
// Created by 27682 on 2025/10/14.
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

constexpr int N = 2e6;
constexpr int sn = 5e3;

int notprime[N], prime[N], p[N];
int split[N][3], g[sn + 10][sn + 10];
int cnt = 0;

void init_gcd() {
    notprime[1] = 1;
    int i, j, d;
    for (i = 2; i < N; i++) {
        if (!notprime[i]) {
            prime[++cnt] = i;
            p[i] = i;
        }
        for (j = 1; j <= cnt; j++) {
            if (prime[j] * i >= N) break;
            d = prime[j] * i;
            notprime[d] = 1;
            p[d] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }

    split[1][0] = split[1][1] = split[1][2] = 1;
    for (i = 2; i < N; i++) {
        memcpy(split[i], split[i / p[i]], sizeof(split[i / p[i]]));
        if (split[i][0] * p[i] <= sn) split[i][0] *= p[i];
        else if (split[i][1] * p[i] <= sn) split[i][1] *= p[i];
        else split[i][2] *= p[i];
    }

    // gcd(0,0)=0 , gcd(0,x)=x
    for (i = 0; i <= sn; i++)
        for (j = 0; j <= i; j++) {
            if (!i || !j) g[i][j] = i | j;
            else g[i][j] = g[j][i] = g[j][i % j]; //j<=i
        }
}

int gcd1(int x, ll y) {
    int ans = 1, i, d;
    for (i = 0; i < 3; i++) {
        if (split[x][i] <= sn) d = g[split[x][i]][y % split[x][i]];
        else d = (y % split[x][i] == 0) ? split[x][i] : 1;
        ans *= d;
        y /= d; //避免算重
    }
    return ans;
}

int ans;

inline void dfs(ll x, ll y, int dep) {
    if (dep > 20) return;
    if (!x || !y) {
        ans = min(ans, dep + 1);
        return;
    }
    ll z = gcd1(x, y);
    if (z != gcd(x, y)) {
        cout << 1 << endl;
    }
    dfs(x - z, y, dep + 1);
    dfs(x, y - z, dep + 1);
}

inline void Zlin() {
    ll a, b;
    cin >> a >> b;
    ans = 30;
    dfs(a, b, 0);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    init_gcd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
