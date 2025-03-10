//
// Created by 27682 on 2025/3/4.
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

struct Ftree {
private:
    vi t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v) {
        while (i < t.size()) {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i) {
        int s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r) {
        if (r < l) return 0;
        return qry1(r) - qry1(l - 1);
    }
} tr[5];

inline void Zlin() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    vector<pii> tag(n + 1);
    for (int i = 1; i <= n; i++) {
        if (t[i] == '1')
            tag[i] = {i, i};
        else if (s[i - 1] == '0' && s[i + 1] == '0')
            tag[i] = {i - 1, i + 1};
        else
            tag[i] = {0, 0};
    }
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
            a[i] = {i, i};
        else if (tag[i - 1].first && tag[i + 1].first)
            a[i] = {tag[i - 1].first, tag[i + 1].second};
        else
            a[i] = {0, 0};
    }
    for (int i = 0; i < 5; i++)
        tr[i].init(n);
    for (int i = 1; i <= n; i++) {
        if (a[i].first == i && a[i].second == i)
            tr[0].upd(i, 1);
        if (a[i].first == i - 1 && a[i].second == i + 1)
            tr[1].upd(i, 1);
        if (a[i].first == i - 2 && a[i].second == i + 1)
            tr[2].upd(i, 1);
        if (a[i].first == i - 1 && a[i].second == i + 2)
            tr[3].upd(i, 1);
        if (a[i].first == i - 2 && a[i].second == i + 2)
            tr[4].upd(i, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        ans += tr[0].qry2(l, r);
        ans += tr[1].qry2(l + 1, r - 1);
        ans += tr[2].qry2(l + 2, r - 1);
        ans += tr[3].qry2(l + 1, r - 2);
        ans += tr[4].qry2(l + 2, r - 2);
        cout << ans << endl;
    }
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