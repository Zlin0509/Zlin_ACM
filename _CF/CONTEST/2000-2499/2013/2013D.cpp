//
// Created by Zlin on 2024/10/22.
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

const ll inf = 1e18;
const int N = 2e5 + 5;
ll n, a[N], b[N], l, r, mid, mx, mm;

bool check1(ll x) {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 1; i < n; i++)
        if (b[i] > x)b[i + 1] += b[i] - x;
    return b[n] <= x;
}

bool check2(ll x) {
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = n; i > 1; i--)
        if (b[i] < x)b[i - 1] -= x - b[i];
    return b[1] >= x;
}

inline void Zlin() {
    l = r = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], r = max(r, a[i]);
    while (l < r) {
        mid = l + r >> 1;
        if (check1(mid)) r = mid;
        else l = mid + 1;
    }
    mx = l;
    r = l, l = 1;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check2(mid)) l = mid;
        else r = mid - 1;
    }
    mm = l;
    cout << mx - mm << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}