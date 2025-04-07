//
// Created by 27682 on 2025/4/7.
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

constexpr int N = 2e5 + 10;
constexpr ll base1 = 113211, base2 = 3431311;
constexpr ll mo1 = 115479311, mo2 = 123121231;


int n, l, r, k;
int ans[N], used[N];
ll Hash1[N], fac1[N], Hash2[N], fac2[N];

inline bool cc(int l, int r, ll tag1, ll tag2) {
    ll now1 = (Hash1[r] - Hash1[l] * fac1[r - l] % mo1 + mo1) % mo1;
    ll now2 = (Hash2[r] - Hash2[l] * fac2[r - l] % mo2 + mo2) % mo2;
    return now1 == tag1 && now2 == tag2;
}

inline int check(int x) {
    if (used[x]) return used[x];
    int cnt = 0;
    for (int i = 0; i <= n - x;) {
        if (cc(i, i + x, Hash1[x], Hash2[x])) ++cnt, i += x;
        else ++i;
    }
    return used[x] = cnt;
}

inline void Zlin() {
    cin >> n >> l >> r;
    for (int i = 0; i <= n + 2; i++)
        ans[i] = used[i] = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        Hash1[i] = (Hash1[i - 1] * base1 + c) % mo1;
        Hash2[i] = (Hash2[i - 1] * base2 + c) % mo2;
    }
    int R = n;
    for (k = l; k <= sqrt(n); k++) {
        int lx = 0, rx = min(R, n / k), mid;
        while (lx < rx) {
            mid = lx + rx + 1 >> 1;
            check(mid) >= k ? lx = mid : rx = mid - 1;
        }
        ans[k] = lx, R = lx;
    }
    for (int len = 1; len <= sqrt(n); len++) {
        k = check(len);
        if (k < l) break;
        ans[k] = max(ans[k], len);
    }
    for (int i = n - 1; i >= l; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = l; i <= r; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    fac1[0] = fac2[0] = 1;
    for (int i = 1; i < N; i++) {
        fac1[i] = fac1[i - 1] * base1 % mo1;
        fac2[i] = fac2[i - 1] * base2 % mo2;
    }
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
