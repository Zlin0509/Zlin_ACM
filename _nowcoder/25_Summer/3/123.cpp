#include <bits/stdc++.h>
using namespace std;
using ll = int;
using ull = unsigned long long;
const int N = 1e6 + 5;
const int M = 21;
const ll inf = 2e9;
const ll mod = 1e9 + 7;
ll n;
vector<ll> v;
bool vis[N];

void dfs(ll x, ll res) {
    if (x == n) {
        v.push_back(res);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(x + 1, res * 10 + i);
        vis[i] = 0;
    }
}

ll w1[10], w2[10], w3[10];

ll merge(ll x, ll y) {
    ll idx = 0;
    while (x) {
        w1[++idx] = x % 10;
        x /= 10;
    }
    idx = 0;
    while (y) {
        w2[++idx] = y % 10;
        y /= 10;
    }
    ll res = 0;
    for (int i = 1; i <= idx; i++) {
        w3[i] = w1[w2[i]];
        res = res * 10 + w3[i];
    }
    return res;
}

ll get(ll x) {
    ll idx = 0;
    while (x) {
        w1[++idx] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= idx; i++) {
        w3[w1[i]] = i;
    }
    ll res = 0;
    for (int i = 1; i <= idx; i++) {
        res = res * 10 + w3[i];
    }
    return res;
}

ll work(ll x) {
    set<ll> st;
    for (auto o: v) {
        ll yy = merge(o, x);
        ll zz = merge(yy, get(o));
        st.insert(zz);
    }
    return st.size();
}

int fac[1000];

void solve() {
    cin >> n;
    dfs(0, 0);
    vector<ll> w;
    ll sum = 0;
    for (auto o: v) {
        ll x = work(o);
        // cout << o << " " << x << "\n";
        sum += x;
        w.push_back(x);
    }
    cout << sum << " " << fac[n] << endl;
    // sort(w.begin(), w.end());
    // for (auto o: w) {
    //     cout << o << " ";
    // }
    // cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; cin >> _;
    fac[0] = 1;
    for (int i = 1; i < 50; i++) fac[i] = fac[i - 1] * i;
    while (_--) solve();
    return 0;
}
