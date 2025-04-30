//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    ll id, a, h;

    bool operator<(const node &x) const {
        if (h != x.h) return h < x.h;
        if (a != x.a) return a < x.a;
        return id < x.id;
    }
};

inline void Zlin() {
    ll n, u, k, hp;
    cin >> n >> u >> k >> hp;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].h;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    vll mx(n + 1);
    mx[n - 1] = a[n - 1].a;
    for (ll i = n - 2; ~i; i--)
        mx[i] = max(mx[i + 1], a[i].a);
    vll at(k);
    at[0] = u;
    for (int i = 1; i < k; i++) at[i] = at[i - 1] + u / 2;
    int ans = 0;
    ll lx = 0, val;
    for (int i = 0; i < n; i++) {
        ll cnt = lower_bound(at.begin(), at.end(), a[i].h) - at.begin() + 1;
        if (cnt > k) {
            lx = max(lx, a[i].h);
            val = k * max(lx, mx[i]);
            hp -= val;
        } else {
            val = (cnt - 1) * max(lx, mx[i]);
            hp -= val;
            if (hp > 0) ++ans;
            val = max(lx, mx[i + 1]);
            hp -= val;
        }
        if (hp <= 0)
            break;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
