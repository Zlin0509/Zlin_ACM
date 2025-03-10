//
// Created by Zlin on 2024/12/15.
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

inline void Zlin() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int ans = 0, sum = m * 2;
    if (a <= m) ans += a, sum -= a;
    else ans += m, sum -= m;
    if (b <= m) ans += b, sum -= b;
    else ans += m, sum -= m;
    ans += min(sum, c);
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
