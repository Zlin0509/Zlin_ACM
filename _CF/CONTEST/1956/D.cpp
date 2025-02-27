//
// Created by 27682 on 2025/2/27.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1);
    vll sum(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ll ans = sum[n];
    vector<pii> op;
    vector tag(n + 3, vector<pii>());
    tag[2].push_back({1, 1});
    for (int i = 3; i <= n; i++) {
        for (pii it: tag[i - 1])
            tag[i].push_back(it);
        tag[i].push_back({0, i - 1});
        tag[i].push_back({0, i - 2});
        for (pii it: tag[i - 1])
            tag[i].push_back(it);
    }
    vll all(1 << n, sum[n]);
    for (int i = 0; i < (1 << n); i++) {
        for (int now = 0, l = 0, r = 0; now <= n; now++) {
            if ((1 << now) & i) {
                if (!l)
                    l = r = now + 1;
                else
                    ++r;
            } else if (l) {
                all[i] += (r - l + 1) * (r - l + 1) - sum[r] + sum[l - 1];
                l = r = 0;
            }
        }
        ans = max(ans, all[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        if (ans == all[i]) {
            for (int now = 0, l = 0, r = 0; now <= n; now++) {
                if ((1 << now) & i) {
                    if (!l)
                        l = r = now + 1;
                    else
                        ++r;
                } else if (l) {
                    bool check = false;
                    for (int x = l; x <= r; x++) {
                        if (!a[x]) {
                            check = true;
                            break;
                        }
                    }
                    op.push_back({l, r});
                    if (check)
                        op.push_back({l, r});
                    for (auto [x, y]: tag[r - l + 1])
                        op.push_back({l + x, l + y});
                    op.push_back({l, r});
                    l = r = 0;
                }
            }
            break;
        }
    }
    cout << ans << ' ' << op.size() << endl;
    for (auto [x, y]: op)
        cout << x << ' ' << y << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}