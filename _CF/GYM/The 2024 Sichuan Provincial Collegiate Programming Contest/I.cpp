//
// Created by Zlin on 2025/5/24.
//

#include "bits/stdc++.h"
#define endl "\n"
#define int long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, l, h;

vector<pii> a(55), pos(55, {-1, -1});

set<int> nx, ny;

bool check(int lx, int ly, int id) {
    int rx = lx + a[id].first - 1, ry = ly + a[id].second - 1;
    if (rx >= l || ry >= h) return false;
    for (int i = 1; i < id; i++) {
        if (pos[i] == make_pair(-1, -1)) continue;
        int llx = pos[i].first, lly = pos[i].second;
        int rrx = llx + a[i].first - 1, rry = lly + a[i].second - 1;
        if ((rrx >= lx && rrx <= rx) || (llx >= lx && llx <= rx) || (rx >= llx && rx <= rrx) || (
                lx >= llx && lx <= rrx)) {
            if (lly >= ly && lly <= ry) return false;
            if (rry >= ly && rry <= ry) return false;
            if (ly >= lly && ly <= rry) return false;
            if (ry >= lly && ry <= rry) return false;
        }
    }
    return true;
}

inline void Zlin() {
    cin >> n >> l >> h;
    nx.insert(0), ny.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        for (int x: nx) {
            for (int y: ny) {
                if (check(x, y, i)) {
                    pos[i] = {x, y};
                    break;
                }
            }
            if (pos[i] != make_pair(-1, -1)) break;
        }
        if (pos[i] == make_pair(-1, -1)) cout << -1 << endl;
        else {
            cout << pos[i].first << ' ' << pos[i].second << endl;
            nx.insert(pos[i].first);
            ny.insert(pos[i].second);
            nx.insert(pos[i].first + a[i].first);
            ny.insert(pos[i].second + a[i].second);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
