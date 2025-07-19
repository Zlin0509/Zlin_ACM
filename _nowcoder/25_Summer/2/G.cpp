//
// Created by 27682 on 2025/7/17.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 5e5 + 10;
constexpr db pi = acos(-1.0L);

int n;
pll a[N], s;

struct node {
    ll dif;
    int id;

    bool operator<(const node &b) const {
        if (dif != b.dif) return dif > b.dif;
        return id < b.id;
    }
};

vector<node> v;

inline ll cal(pll a, pll b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

inline ll tag(pll a, pll b, pll c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

inline db angle(pll a, pll b, pll c) {
    db vx1 = (db) (b.first - a.first), vy1 = (db) (b.second - a.second);
    db vx2 = (db) (c.first - a.first), vy2 = (db) (c.second - a.second);
    db ang = atan2l(vx1 * vy2 - vy1 * vx2, vx1 * vx2 + vy1 * vy2);
    if (ang <= 0) ang += 2 * pi;
    return ang;
}

db ans, tmp;

bool cmp(const pll &a, const pll &b) {
}

inline void Zlin() {
    cin >> n >> s.first >> s.second;
    bool check = true;
    for (int i = 0; i < n; i++) {
        if (tag(s, a[i], a[(i + 1) % n]) < 0) {
            check = false;
            break;
        }
    }
    if (!check) ans = 2 * pi;
    else {
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            v.emplace_back(cal(a[i], s), i);
        }
        sort(v.begin(), v.end());
        ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i == n - 1 || v[i].dif != v[i + 1].dif) {
                ans = max(ans, angle(s, a[v[i].id], a[v[0].id]));
                break;
            }
            ans = max(ans, angle(s, a[v[i].id], a[v[i + 1].id]));
        }
    }
    cout << fixed << setprecision(16) << (double) ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
