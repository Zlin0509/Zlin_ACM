//
// Created by 27682 on 2025/4/15.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

i128 cal(i128 n, i128 k, i128 x) {
    k -= x * 4;
    n += x * 20;
    i128 res = 0;
    for (int i = 0; i < 4; i++) {
        res = max(res, n * k);
        --k;
        n += n % 10;
    }
    return res;
}

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    if (n % 10 == 0 || k == 1) {
        cout << 1ll * n * k << endl;
        return;
    }
    if (n % 10 == 5) {
        cout << max(1ll * n * k, 1ll * (n + 5) * (k - 1)) << endl;
        return;
    }
    i128 ans = 1ll * n * k;
    while (n % 10 != 2) {
        ans = max(ans, (i128) n * k);
        n += n % 10;
        --k;
    }
    i128 l = 0, r = k / 4;
    ans = max(ans, n * r);
    while (l < r) {
        i128 ml = l + (r - l) / 3, mr = r - (r - l) / 3;
        i128 al = cal(n, k, ml), ar = cal(n, k, mr);
        ans = max({ans, al, ar});
        if (al >= ar)
            r = mr - 1;
        else
            l = ml + 1;
    }
    ans = max({ans, cal(n, k, r), cal(n, k, l)});

    string op;
    while (ans) {
        op += char(ans % 10 + '0');
        ans /= 10;
    }
    reverse(op.begin(), op.end());
    cout << op << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
