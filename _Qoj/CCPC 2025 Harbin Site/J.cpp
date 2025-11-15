#include <bits/stdc++.h>
using namespace std;
using ll = int;
const int N = 4e7 + 5;
string s;
ll n;
array<int, N> r;
ll lx[N], rx[N], pl[N], pr[N];
ll vis[N];

pair<ll, ll> work(ll x, ll y, ll mid) {
    ll L = lx[x], R = rx[y];
    if (L == -1 || R == -1) {
        if (vis[x] || vis[y]) {
            return work(x + 1, y - 1, mid);
        }
        ll _x = pr[x], _y = pl[y];
        if (_x > mid) {
            if (_y >= mid) return work(mid + mid - _y, _y, mid);
            return {0, 0};
        }
        if (_y - mid < 0 || mid - _x < _y - mid) return work(_x, mid + mid - _x, mid);
        return work(mid + mid - _y, _y, mid);
    }
    return {L, R};
}

void manacher(string &s) {
    string t = "#";
    ll idx = 0;
    lx[0] = 0, rx[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != 'w') {
            t += c, t += '#';
            idx++;
            lx[idx] = rx[idx] = i;
            vis[idx] = 1;
            lx[++idx] = i + 1, rx[idx] = i;
            vis[idx] = 0;
        } else {
            t += 'v';
            idx++;
            lx[idx] = i;
            rx[idx] = -1;
            vis[idx] = 0;
            t += '#';
            idx++;
            lx[idx] = rx[idx] = -1;
            vis[idx] = 0;
            t += 'v';
            idx++;
            lx[idx] = -1, rx[idx] = i;
            vis[idx] = 0;
            t += '#';
            idx++;
            lx[idx] = i + 1, rx[idx] = i;
            vis[idx] = 0;
        }
    }
    int n = t.size();
    ll x = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) x = i;
        pl[i] = x;
    }
    x = n;
    for (int i = n - 1; i >= 0; i--) {
        if (vis[i]) x = i;
        pr[i] = x;
    }
    for (int i = 0; i < n; i++) r[i] = 0;
    ll mx = 0;
    pair<ll, ll> xx;
    for (int i = 0, j = 0; i < n; i++) {
        if (j + r[j] > i) r[i] = min(r[2 * j - i], j + r[j] - i);
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) ++r[i];
        if (i + r[i] > j + r[j]) j = i;
    }
    for (int i = 0; i < n; i++) {
        ll x = i - r[i] + 1, y = i + r[i] - 1;
        pair<ll, ll> yy = work(x, y, i);
        ll len = yy.second - yy.first + 1;
        if (mx < len) mx = len, xx = yy;
    }
    for (int i = xx.first; i <= xx.second; i++) cout << s[i];
    cout << "\n";
}

void solve() {
    cin >> n >> s;
    manacher(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
