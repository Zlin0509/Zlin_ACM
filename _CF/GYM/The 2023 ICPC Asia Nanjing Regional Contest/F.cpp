//
// Created by Zlin on 2024/10/13.
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

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a.size() < b.size(); // 大的优先排在后面（小顶堆）
    }
};

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vi cnt(m + 1);
    vector<vi> a(n), b(n + 1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 1, y; j <= x; j++) {
            cin >> y;
            cnt[y]++;
            a[i].push_back(y);
        }
    }
    for (int i = 0; i < n; i++) for (auto j: a[i]) if (cnt[j] >= 2) b[i + 1].push_back(j);
    int ans1 = 0, ans2 = 0;
    priority_queue<vi, vector<vi>, cmp> p;
    for (int i = 1; i <= n; i++) {
        for (auto j: b[i]) --cnt[j];
        p.push(b[i]);
        while (!p.empty()) {
            bool check = true;
            vi u = p.top();
            p.pop();
            for (auto j: u) {
                if (!cnt[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                if (!ans1) ans1 = i;
                else ans2 = i;
            }
            if (ans1 && ans2) break;
        }
        if (ans1 && ans2) break;
    }
    if (!ans1 || !ans2) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        cout << ans1 << ' ' << ans2 << ' ';
        for (int i = 1; i <= n; i++) if (i != ans1 && i != ans2) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}