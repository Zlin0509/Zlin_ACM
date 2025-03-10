//
// Created by Zlin on 2024/10/23.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
int n, a[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int tag = a[1];
    for (int i = 1; i <= n; i++) tag = gcd(tag, a[i]);
    ll ans = 0;
    for (int i = 1; i <= n; i++) a[i] /= tag;
    int now = a[1], cur, cnt = n;
    ans += now * tag;
    --cnt;
    while (now != 1) {
        cur = now;
        for (int i = 1; i <= n; i++)
            cur = min(cur, gcd(now, a[i]));
        now = cur;
        ans += now * tag;
        --cnt;
    }
    ans += 1ll * tag * cnt;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}