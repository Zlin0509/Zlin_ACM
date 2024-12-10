//
// Created by Zlin on 2024/12/1.
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

const int N = 200010;
int n, m;
ll sum = 0;
vi a(N), b(N), used(N);

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i], sum += b[i];
    ll l = 1, r = n, mid;
    auto check = [](ll x) {
        ll now = sum, sur = 0;
        for (int i = x; i; i--) {
            if (a[i] && !used[a[i]]) {
                used[a[i]] = 1;
                now -= b[a[i]];
                sur += b[a[i]];
            } else if (sur) --sur;
        }
        for (int i = 1; i <= n; i++) used[i] = 0;
        return (now + sur == 0);
    };
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (!check(l)) {
        cout << -1 << '\n';
        return;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}