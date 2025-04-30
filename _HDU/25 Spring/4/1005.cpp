//
// Created by 27682 on 2025/3/28.
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

inline void Zlin() {
    int n, k;
    ldb p;
    cin >> p >> n >> k;
    vll b;
    vector<ldb> a;
    for (int i = 1; i <= n; i++) {
        int op, x;
        cin >> op >> x;
        if (op) {
            b.push_back(x);
        } else {
            a.push_back(0.1 * x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    for (int i = 1; i < b.size(); i++)
        b[i] += b[i - 1];
    for (int i = 1; i < a.size(); i++)
        a[i] *= a[i - 1];
    ldb ans = p, val;
    if (!b.empty()) ans = min(ans, ans - b[min(k - 1, (int)b.size() - 1)]);
    for (int i = 0; i < min(k, (int) a.size()); i++) {
        val = p * a[i];
        if (!b.empty() && k - i - 2 >= 0)
            val -= b[min(k - i - 2, (int) b.size() - 1)];
        ans = min(ans, val);
    }
    ans = max((ldb) 0, ans);
    cout << fixed << setprecision(2) << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
