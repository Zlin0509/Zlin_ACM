//
// Created by 27682 on 2025/4/11.
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

constexpr int N = 1e5 + 10;

ll st[N][22], sum[N];
int n;
ll tag;

inline void prework() {
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + abs(st[i][0] - st[i - 1][0]);
    int t = log(n) / log(2) + 1;
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

inline ll query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

bool check(int x) {
    for (int i = 1; i <= n - x + 1; i++) {
        ll res = 0;
        ll val = query(i, i + x - 1);
        if (i > 1) res += sum[i - 1] + abs(val - st[i - 1][0]);
        if (i + x - 1 < n) res += sum[n] - sum[i + x] + abs(val - st[i + x][0]);
        if (res <= tag) return true;
    }
    return false;
}

inline void Zlin() {
    cin >> n >> tag;
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        for (int j = 0; j < 22; j++) st[i][j] = 0;
        cin >> st[i][0];
    }
    prework();
    if (sum[n] <= tag) {
        cout << 0 << endl;
        return;
    }
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
