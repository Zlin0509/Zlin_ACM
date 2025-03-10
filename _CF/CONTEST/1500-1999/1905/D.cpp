//
// Created by 27682 on 2025/2/26.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vi tag(n + 1, 0);
    ll res = 0, now = 0;
    deque<pii> dq;
    for (int i = 1; i <= n; i++) {
        tag[a[i]]++;
        while (tag[now])
            ++now;
        dq.push_back({now, 1});
        res += now;
    }
    ll ans = res;
    for (int i = 1; i <= n; i++) {
        pii me = {a[i], 0};
        res -= dq.front().first;
        dq.front().second--;
        if (!dq.front().second)
            dq.pop_front();
        while (!dq.empty() && dq.back().first >= me.first) {
            res -= 1ll * dq.back().first * dq.back().second;
            me.second += dq.back().second;
            dq.pop_back();
        }
        dq.push_back(me);
        res += 1ll * me.first * me.second;
        dq.push_back({n, 1});
        res += n;
        ans = max(ans, res);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}
