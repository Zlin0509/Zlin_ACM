#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
const ll inf = 1e18;
const ll mod = 998244353;

typedef long double db;

constexpr db dif = 5e-8;

struct node {
    db x, y;
} s[3];

db a, b, c, l, r, lx, rx, vl, vr, rr, all;
db aa, bb, cc, rrr;

db cal_dis(node a, node b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

db cal_dis1(node a, node b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

db cal(db x) {
    db y = all - x;
    db res = 0;
    res += sqrt(aa + rrr - cos(x) * 2 * a * rr);
    res += sqrt(bb + rrr - cos(y) * 2 * b * rr);
    return res;
}

bool check() {
    if (a <= rr + dif || b <= rr + dif) return true;
    db tmp = aa + cc - bb;
    if (tmp <= dif) return false;
    tmp = bb + cc - aa;
    if (tmp <= dif) return false;
    db tr = sqrt(1 - pow((aa + cc - bb) / (2 * a * c), 2)) * a;
    return tr <= rr + dif;
}

void solve() {
    for (int i = 0; i < 3; i++) cin >> s[i].x >> s[i].y;
    swap(s[0], s[2]);
    cin >> rr;
    a = cal_dis(s[0], s[1]), b = cal_dis(s[0], s[2]), c = cal_dis(s[1], s[2]);
    aa = cal_dis1(s[0], s[1]), bb = cal_dis1(s[0], s[2]), cc = cal_dis1(s[1], s[2]), rrr = rr * rr;
    if (a > b) swap(a, b), swap(aa, bb);
    if (check()) {
        cout << fixed << setprecision(12) << c << endl;
        return;
    }
    l = 0, r = all = acos((aa + bb - cc) / (2 * a * b));
    for (int ttt = 1; ttt <= 3000; ttt++) {
        lx = l + (r - l) / 3, rx = r - (r - l) / 3;
        vl = cal(lx), vr = cal(rx);
        if (vl < vr) r = rx;
        else l = lx;
    }
    db ans = cal(l);
    cout << fixed << setprecision(16) << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
