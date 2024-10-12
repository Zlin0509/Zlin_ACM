//
// Created by Zlin on 2024/10/10.
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

const int N = 3e3 + 10;

int n;

struct node {
    ll x, y;
    int id;

    bool operator<(const node &b) const {
        if (x != b.x) return x < b.x;
        return y < b.y;
    }

    node operator-(const node &b) const {
        return {x - b.x, y - b.y};
    }
} o;

ll cross(node a, node b, node c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool cmp(node a, node b) {
    if (cross(o, a, b) == 0) return a.x < b.x;
    return cross(o, a, b) > 0;
}

vector<node> a(N);
vi vis(N, 0);

void cal() {
    vector<node> res;
    for (int i = 0; i < n; i++) {
        while (res.size() >= 2 && cross(res[res.size() - 2], res.back(), a[i]) <= 0)
            res.pop_back();
        res.push_back(a[i]);
    }
    int t = res.size() + 1;
    for (int i = n - 1; i >= 0; i--) {
        while (res.size() >= t && cross(res[res.size() - 2], res.back(), a[i]) <= 0)
            res.pop_back();
        res.push_back(a[i]);
    }
    res.pop_back();
    for (auto it: res)
        vis[it.id] = 1;
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a.begin(), a.begin() + n);
    cal();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (vis[a[i].id]) continue;
        vector<node> all;
        o = a[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            all.push_back(a[j]);
        }
        sort(all.begin(), all.end(), cmp);
        for (int j = 0; j < n - 1; j++)
            if (vis[all[j].id] == 1 && vis[all[(j + 1) % (n - 1)].id] == 1) ++ans;
//        cout << ans << ' ';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}