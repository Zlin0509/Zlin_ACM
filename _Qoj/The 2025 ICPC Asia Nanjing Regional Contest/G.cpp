//
// Created by Zlin on 2025/11/12.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 5;
constexpr ll INF = 1e18;

int n, q;
ll v[N], l[N], ans[N], sumv, suml;
pii t[N];
set<pll> sv, sl, st;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> l[i], l[i] *= -1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> t[i].first;
        t[i].second = i;
    }
    sort(t + 1, t + 1 + q);
    sumv = suml = 0;
    sv.clear(), sl.clear(), st.clear();
    for (int i = 1; i <= n; i++) {
        sumv += v[i];
        suml += l[i];
        if (l[i]) st.insert({(ll) ceil(-1.0 * v[i] / l[i]), i});
        else st.insert({INF, i});
        sv.insert({v[i], i});
        sl.insert({l[i], i});
    }
    for (int i = 1; i <= q; i++) {
        while (!st.empty() && st.begin()->first <= t[i].first) {
            int id = st.begin()->second;
            st.erase(st.begin());
            suml -= l[id];
            sumv -= max(0ll, v[id] + l[id] * t[i - 1].first)
                    - max(0ll, v[id] + l[id] * t[i].first);
        }
        sumv += suml * (t[i].first - t[i - 1].first);
        while (sv.size() > 1) {
            auto [a1, id] = *sl.begin();
            ll b1 = v[id];
            sl.erase(sl.begin());
            sv.erase(sv.find({b1, id}));
            auto [b2, iid] = *sv.begin();
            ll a2 = l[iid];
            sv.erase(sv.begin());
            sl.erase(sl.find({a2, iid}));
            ll val1 = max(0ll, a1 * t[i].first + b1), val2 = max(0ll, a2 * t[i].first + b2);
            ll val3 = max(0ll, max(a1, a2) * t[i].first + max(b1, b2));
            if (val1 + val2 > val3) {
                sl.insert({a1, id});
                sl.insert({a2, iid});
                sv.insert({b1, id});
                sv.insert({b2, iid});
                break;
            }
            sumv += val3 - val1 - val2;
            l[id] = max(a1, a2), v[id] = max(b1, b2);
            sl.insert({l[id], id});
            sv.insert({v[id], id});
            if (val1) {
                suml -= a1;
                if (a1) st.erase(st.find({(ll) ceil(-1.0 * b1 / a1), id}));
                else st.erase(st.find({INF, id}));
            }
            if (val2) {
                suml -= a2;
                if (a2) st.erase(st.find({(ll) ceil(-1.0 * b2 / a2), iid}));
                else st.erase(st.find({INF, iid}));
            }
            if (val3) {
                suml += max(a1, a2);
                if (l[id]) st.insert({(ll) ceil(-1.0 * v[id] / l[id]), id});
                else st.insert({INF, id});
            }
        }
        // for (const auto [x, id]: st) cout << v[id] << ' ' << l[id] << endl;
        // cout << endl;
        ans[t[i].second] = max(0ll, sumv);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << " \n"[i == q];
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
