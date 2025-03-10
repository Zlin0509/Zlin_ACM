//
// Created by Zlin on 2024/9/4.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

const ll inf = 1e18;

struct ss {
    ll a, b;

    bool operator<(const ss &x) const {
        if (b != x.b) return b > x.b;
        return a < x.a;
    }
};

inline void Zlin() {
    int n, k;
    ll ans = 0, sum = 0;
    cin >> n >> k;
    vll a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<ss> s;
    s.push_back({inf, inf});
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) s.push_back({a[i], b[i]});
    }
    sort(s.begin(), s.end());
    n = s.size() - 1;
    if (n < 1 || k >= n) {
        cout << 0 << '\n';
        return;
    }
    b[n] = s[n].b - s[n].a;
    for (int i = n - 1; i >= 1; i--) b[i] = b[i + 1] + s[i].b - s[i].a;
    if (k == 0) {
        cout << b[1] << '\n';
        return;
    }
    priority_queue<ll, vll, less<ll>> p;
    for (int i = 1; i <= k; i++) sum += s[i].a, p.push(s[i].a);
    ans = max(ans, b[k + 1] - sum);
    for (int i = k + 1; i < n; i++) {
        if (s[i].a < p.top()) {
            sum += s[i].a - p.top();
            p.pop();
            p.push(s[i].a);
            ans = max(ans, b[i + 1] - sum);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}