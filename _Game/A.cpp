#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

constexpr ll mo = 1000000007;

int n, k;

inline void Zlin() {
    cin >> n >> k;
    ll ans = k;
    for (int i = 1; i < n; i++) ans = ans * (k - 1) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
