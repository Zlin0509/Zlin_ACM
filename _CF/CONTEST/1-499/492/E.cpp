//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return gcd;
}

constexpr int N = 1e6 + 5;

int ans[N], tx[N], ty[N];

inline void Zlin() {
    int n, m, dx, dy, tmp;
    cin >> n >> m >> dx >> dy;
    exgcd(dx, n, dx, tmp);
    exgcd(dy, n, dy, tmp);
    dx = (dx + n) % n, dy = (dy + n) % n;
    int id = 0;
    for (int i = 1, x, y, xx, yy; i <= m; i++) {
        cin >> x >> y;
        xx = 1ll * x * dx % n, yy = 1ll * y * dy % n;
        tmp = xx <= yy ? yy - xx : yy - xx + n;
        ans[tmp]++;
        tx[tmp] = x, ty[tmp] = y;
        if (ans[tmp] > ans[id]) id = tmp;
    }
    cout << tx[id] << ' ' << ty[id] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
