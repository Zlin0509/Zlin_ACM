#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
const int N = 2e5 + 7;
using ll = long long;
const int p = 998244353;
const int mod = 998244353;
ll fac[N];

void init(ll n) {
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)fac[i] = fac[i - 1] * i % p;
}

ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % p;
        a = a * a % p, b >>= 1;
    }
    return res;
}

ll inv(ll a) { return qmi(a, p - 2); }

ll C(ll n, ll m) {
    if (n < 0 || m < 0 || m > n)return 0;
    return fac[n] * inv(fac[n - m] * fac[m] % p) % p;
}

int pos[N];

void solved() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            c++, pos[c] = i;
        }
    }
    if (c == n and k <= n) {
        cout << 1 << '\n';
        return;
    }
    int cnt = 0;
    int ans = 0;
    int lastr = 0;
    for (int l = 1, r = 1; r <= n; r++) {
        cnt += s[r] - '1';
        if (cnt >= k) {
            while (r + 1 <= n && s[r + 1] == '0') r++;
            ans += C(r - l + 1, k);
            ans %= mod;
            ans = (ans - C(lastr - l + 1, k - 1) + mod) % mod;
            l = pos[cnt - k + 1] + 1;
            lastr = r;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    init(2e5);
    while (_--)solved();
    return 0;
}
