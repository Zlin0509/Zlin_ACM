//
// Created by Zlin on 2024/10/23.
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

struct ss {
    int val, cnt;

    bool operator<(const ss &x) const {
        return val > x.val;
    }

    ss operator+(const ss &x) const {
        return {x.val, cnt + x.cnt};
    }
};

const int N = 1e6 + 5;
int n, m, k;

bool check(ss a, ss b, int tag) {

}

inline void Zlin() {
    cin >> n >> m >> k;
    vi d(n), a(n);
    for (int i = 0; i < n; i++) cin >> d[i] >> a[i];
    priority_queue<ss> q;
    int l = 0, ans = 0, dif, tag;
    while (l < n - 1) {
        ss u{0, 0};
        dif = d[l + 1] - d[l];
        q.push({d[l] + k - 1, a[l]});
        while (u.cnt < dif * m && !q.empty()) {
            if (check(u, q.top(), tag)) u = u + q.top();
            q.pop();
        }
        ans += u.val / m;
        u.val %= m;
        if (!u.val) q.push(u);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}