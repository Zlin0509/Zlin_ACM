//
// Created by Zlin on 2024/10/19.
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
const int N = 2e5 + 10;
ll n, k, m, c, d;
ll a[N];
vi op1(N), op2(N);

bool check(ll x) {
    for (int i = 1; i <= n; i++) op1[i] = op2[i] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) ++cnt;
        else {
            if (c + a[i] >= x) {
                op1[max(i - (int) m + 1, 1)]++;
                op2[i]++;
            } else if (d) {
                if (min((int) m - 1, i - 1) * d + c + a[i] >= x) {
                    op1[max(1, i - (int) m + 1)]++;
                    op2[i - (int) ceil((double) (x - a[i] - c) / (double) d)]++;
                }
            }
        }
    }
    for (int i = 1; i <= n - m + 1; i++) {
        cnt += op1[i];
        if (cnt >= k) return true;
        cnt -= op2[i];
    }
    return false;
}

inline void Zlin() {
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll l = 0, r = 1e15, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}