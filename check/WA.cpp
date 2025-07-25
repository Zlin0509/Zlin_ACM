#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(time(0));
typedef uint64_t hash_t;
ll n, a[20], b[20], c[20];

void solve() {
    ll res = 0;
    for (int i = 1; i <= 13; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + 13);
    ll sum = 0, sumc = 0, suma = 0;
    for (int i = 1; i <= 13; i++) {
        c[i] = a[i] % 3;
        b[i] = a[i] - c[i];
        sum += b[i];
        sumc += c[i];
        suma += a[i];
    }
    if (a[13] >= (suma - a[13]) * 3) {
        cout << suma - a[13] << "\n";
    } else {
        ll ans = min(sum / 3, suma / 4);
        cout << ans << "\n";
    }
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
