#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
constexpr ll mo = 998244353;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << 77987843ll * 64 % mo << endl;

    return 0;
}
