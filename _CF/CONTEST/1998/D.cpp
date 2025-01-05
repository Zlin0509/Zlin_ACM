//
// Created by Zlin on 2024/9/11.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;

struct node {
    ll a, b;

    bool operator<(const node x) const {
        if (a != x.a) return a < x.a;
        return b < x.b;
    }
} a[N];

ll ans, n, k;

inline bool check(int mid) {
    int cnt = 0;
    ll kk = k;
    for (int i = n - 1; i; i--) {
        if (a[i].a >= mid) ++cnt;
        else if (a[i].b) {
            if (kk >= mid - a[i].a) kk -= mid - a[i].a, ++cnt;
            else break;
        }
    }
    return cnt >= n - n / 2;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].a;
    for (int i = 1; i <= n; i++) cin >> a[i].b;
    sort(a + 1, a + 1 + n);
    ans = a[n].a + a[n / 2].a;
    for (int i = 1; i <= n; i++)
        if (a[i].b) {
            if (i <= n / 2) ans = max(ans, a[i].a + k + a[n / 2 + 1].a);
            else ans = max(ans, a[i].a + k + a[n / 2].a);
        }
    int l = 1, r = 1e9, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    ans = max(ans, a[n].a + l);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}