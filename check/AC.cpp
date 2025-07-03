#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 1 << 13;
const ll mod = 998244353;
const ll inf = 1e18 + 1;
const ull base = 233;
ll n, cnt[N], m;
ll a[N], b[N];
vector<ll> g[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    priority_queue<ll, vector<ll>, greater<long long> > pq1;
    ll cnt2 = 0, cnt1 = 0;
    for (int i = n - m + 1, j = 1; i <= n; i++, j++) {
        if (a[i] > b[j]) {
            cout << "-1\n";
            return;
        }
        cnt2 += b[j] - a[i];
    }
    // cout << cnt2 << "\n";
    if (cnt2 > n - m) {
        cout << "-1\n";
        return;
    }
    cnt1 = n - m - cnt2;
    for (int i = 1; i <= n; i++) {
        pq1.push(a[i]);
    }
    vector<ll> ans;
    // cout << cnt1 << " " << cnt2 << "\n";
    ll xx = a[n - m + 1];
    while (cnt1--) {
        if (pq1.size() < m) {
            cout << "-1\n";
            return;
        }
        ll x = pq1.top();
        ans.push_back(x);
        if (x + 1 > xx) {
            xx = x + 1;
            cnt1++;
        }
        pq1.pop();
        pq1.push(x + 1);
        pq1.pop();
    }
    // cout << ans.size() << "\n";
    ll idx = 0;
    while (pq1.size()) {
        a[++idx] = pq1.top();
        pq1.pop();
    }
    n = idx;
    for (int i = n - m + 1, j = 1; i <= n; i++, j++) {
        if (a[i] > b[j]) {
            cout << "-1\n";
            return;
        }
        pq1.push(a[i]);
    }
    idx = 1;
    while (idx <= m) {
        while (pq1.top() < b[idx]) {
            ll x = pq1.top();
            ans.push_back(x);
            pq1.pop();
            pq1.push(x + 1);
        }
        pq1.pop();
        idx++;
    }
    cout << ans.size() << "\n";
    for (auto o: ans) cout << o << " ";
    cout << "\n";
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
