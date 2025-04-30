//
// Created by 27682 on 2025/3/24.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n), d(n);
    for (int &it: a) cin >> it;
    for (int &it: d) cin >> it;
    vector in(n, vi()), out(n, vi());
    for (int i = 0, l, r; i < n; i++) {
        l = i - d[i];
        r = i + d[i];
        l = max(0, l);
        r = min(n - 1, r);
        in[l].push_back(i);
        out[r].push_back(i);
    }
    auto check = [&](int x) {
        vi b = a;
        priority_queue<pii, vector<pii>, greater<pii> > q;
        for (int i = 0, val, tag, z; i < n; i++) {
            val = 0;
            for (int id: in[i])
                q.push({min(n - 1, id + d[id]), id});
            while (val < x && !q.empty()) {
                tag = q.top().second;
                q.pop();
                z = min(x - val, b[tag]);
                b[tag] -= z;
                val += z;
                if (b[tag])
                    q.push({min(n - 1, tag + d[tag]), tag});
            }
            for (int id: out[i])
                if (b[id])
                    return false;
        }
        return true;
    };
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
