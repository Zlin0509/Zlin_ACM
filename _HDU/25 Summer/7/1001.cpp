#include <bits/stdc++.h>
using namespace std;

int n, k;
int p[10005 * 10005];

struct node {
    int x, y, val;
} val[10005];

int x, y, len1, len2, x2, y2, nx, ny, lx, rx;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i].x >> val[i].y >> val[i].val;
    for (int i = 1, pos; i <= n; i++) {
        pos = val[i].x * n + val[i].y;
        if (p[pos] > 0) p[pos] = 0;
        p[pos] -= val[i].val;
    }
    for (int i = 1, pos; i <= n; i++) {
        x = 0;
        for (int j = 1; j <= n; j++) {
            pos = i * n + j;
            if (p[pos] < 0) x -= p[pos];
            p[pos] = p[pos - n] + x;
        }
    }
    int ans = 0;
    for (int l = 1, r; l <= k;) {
        r = k / (k / l);
        for (int i = 1; i <= n; i++) {
            x = val[i].x, y = val[i].y;
            len1 = r, len2 = k / r;
            if (len1 < len2) {
                lx = max(0, len1 - x), rx = min(len1, n - x + 1);
                for (int j = lx; j < rx; j++) {
                    x2 = x + j, y2 = y;
                    nx = x2 - len1 + 1, ny = max(1, y2 - len2 + 1);
                    ans = max(
                        ans, p[x2 * n + y2] - p[x2 * n + ny - 1] - p[(nx - 1) * n + y2] + p[(nx - 1) * n + ny - 1]);
                }
            } else {
                lx = max(0, len2 - y), rx = min(len2, n - y + 1);
                for (int j = lx; j < rx; j++) {
                    x2 = x, y2 = y + j;
                    nx = max(1, x2 - len1 + 1), ny = y2 - len2 + 1;
                    ans = max(
                        ans, p[x2 * n + y2] - p[x2 * n + ny - 1] - p[(nx - 1) * n + y2] + p[(nx - 1) * n + ny - 1]);
            }
        }
        l = r + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
