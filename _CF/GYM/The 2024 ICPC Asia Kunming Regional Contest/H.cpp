//
// Created by 27682 on 2025/3/30.
//
#include "bits/stdc++.h"
using namespace std;
constexpr double pi = 3.14159265358979323846;

struct node {
    long long x, y;
};

long long cross(node a, node b) {
    return a.x * b.x + a.y * b.y;
}

double clen(node a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

double cal(node a, node b) {
    return acos(cross(a, b) / (clen(a) * clen(b)));
}

struct xx {
    double val;
    int cnt;
};

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<double> a;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (!x && !y) {
            --k;
        } else {
            double val = cal({x, y}, {1, 0});
            if (y < 0)
                val = 2 * pi - val;
            a.push_back(val);
        }
    }
    double ans = 0.0;
    if (k <= 0) ans = 0;
    else if (k == n) ans = 2 * pi;
    else {
        sort(a.begin(), a.end());
        vector<xx> have;
        xx now = {100, 0};
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == now.val)
                ++now.cnt;
            else {
                if (now.cnt)
                    have.push_back(now);
                now = {a[i], 1};
            }
        }
        if (now.cnt) have.push_back(now);
        vector<long long> sum(have.size() * 2);
        for (int i = 0; i < have.size(); i++)
            sum[i] = sum[i + have.size()] = have[i].cnt;
        for (int i = 1; i < sum.size(); i++)
            sum[i] = sum[i] + sum[i - 1];
        for (int i = 0; i < have.size(); i++) {
            int l = i, r = lower_bound(sum.begin(), sum.end(), l ? sum[l - 1] + k + 1 : k + 1) - sum.begin();
            if (r < have.size())
                ans = max(ans, have[r].val - have[l].val);
            else
                ans = max(ans, 2 * pi - have[l].val + have[r - have.size()].val);
        }
    }
    cout << fixed << setprecision(12) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}
