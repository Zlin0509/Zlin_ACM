//
// Created by Zlin on 2024/9/19.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;

inline void Zlin() {
    int n, a, b, dif;
    cin >> n >> a >> b;
    if (a == b)dif = a;
    else dif = gcd(a, b);
//    cout<<dif<<' ';
    vll p, q;
    map<int, int> used;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (!used[x])++used[x], p.push_back(x);
    }
    sort(p.begin(), p.end());
    int y = p.back(), r = y;
    q.push_back(y);
    for (int i = 0, k1, k2, d1, d2; i < p.size(); i++) {
        k1 = (y - p[i]) / dif;
        k2 = k1 + 1;
        k1 = k1 * dif + p[i];
        k2 = k2 * dif + p[i];
        q.push_back(k1);
    }
    ll ans = 1e9;
    sort(q.begin(), q.end());
    int len = unique(q.begin(), q.end()) - q.begin();
    for (int i = 0; i < len; i++) {
        ans = min(ans, r - q[i]);
        r = q[i] + dif;
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