//
// Created by Zlin on 2025/10/8.
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

struct Node {
    string name;
    array<int, 3> s;
} s1, s2;

vector<Node> a1, a2;

int n, cnt[3], tag[3], tag1[3];
int m, p, q;

inline bool cmp(const Node &a, const Node &b) {
    int sum1 = a.s[0] + a.s[1] + a.s[2], sum2 = b.s[0] + b.s[1] + b.s[2];
    if (sum1 != sum2) return sum1 > sum2;
    if (a.s[0] != b.s[0]) return a.s[0] > b.s[0];
    return a.name < b.name;
}

unordered_map<string, int> mp;

inline bool cmp1(const pair<string, array<int, 2> > &a, const pair<string, array<int, 2> > &b) {
    if (mp[a.first] != mp[b.first]) return mp[a.first] > mp[b.first];
    if (a.second[0] != b.second[0]) return a.second[0] > b.second[0];
    if (a.second[1] != b.second[1]) return a.second[1] > b.second[1];
    return a.first < b.first;
}

inline bool cmp2(const Node &a, const Node &b) {
    if (a.s[0] != b.s[0]) return a.s[0] > b.s[0];
    return a.name < b.name;
}

inline bool cal(const Node &a, const Node &b) {
    return a.s[0] == b.s[0];
}

inline bool check(Node s1, Node s2) {
    mp.clear();
    vector<Node> t;

    t = a1, t.emplace_back(s1);
    sort(t.begin(), t.end(), cmp2);
    tag[0] = tag1[0], tag[1] = tag1[1], tag[2] = tag1[2];
    while (tag[0] < t.size() && cal(t[tag[0]], t[tag[0] - 1])) ++tag[0];
    while (tag[1] < t.size() && cal(t[tag[1]], t[tag[1] - 1])) ++tag[1];
    while (tag[2] < t.size() && cal(t[tag[2]], t[tag[2] - 1])) ++tag[2];

    sort(t.begin(), t.begin() + tag[0], cmp);
    for (int i = 0; i < cnt[0]; i++) mp[t[i].name] += 15;
    sort(t.begin() + cnt[0], t.begin() + tag[1], cmp);
    for (int i = cnt[0]; i < cnt[1]; i++) mp[t[i].name] += 10;
    sort(t.begin() + cnt[1], t.begin() + tag[2], cmp);
    for (int i = cnt[1]; i < cnt[2]; i++) mp[t[i].name] += 5;

    t = a2, t.emplace_back(s2);
    sort(t.begin(), t.end(), cmp2);
    tag[0] = tag1[0], tag[1] = tag1[1], tag[2] = tag1[2];
    while (tag[0] < t.size() && cal(t[tag[0]], t[tag[0] - 1])) ++tag[0];
    while (tag[1] < t.size() && cal(t[tag[1]], t[tag[1] - 1])) ++tag[1];
    while (tag[2] < t.size() && cal(t[tag[2]], t[tag[2] - 1])) ++tag[2];

    sort(t.begin(), t.begin() + tag[0], cmp);
    for (int i = 0; i < cnt[0]; i++) mp[t[i].name] += 15;
    sort(t.begin() + cnt[0], t.begin() + tag[1], cmp);
    for (int i = cnt[0]; i < cnt[1]; i++) mp[t[i].name] += 10;
    sort(t.begin() + cnt[1], t.begin() + tag[2], cmp);
    for (int i = cnt[1]; i < cnt[2]; i++) mp[t[i].name] += 5;

    vector<pair<string, array<int, 2> > > vx;
    for (int i = 0; i < n - 1; i++)
        vx.emplace_back(
            a1[i].name, array{
                a1[i].s[0] + a1[i].s[1] + a1[i].s[2] + a2[i].s[0] + a2[i].s[1] + a2[i].s[2],
                a1[i].s[0] + a2[i].s[0]
            });
    vx.emplace_back(
        s1.name, array{s1.s[0] + s1.s[1] + s1.s[2] + s2.s[0] + s2.s[1] + s2.s[2], s1.s[0] + s2.s[0]});
    sort(vx.begin(), vx.end(), cmp1);
    // for (const auto &p: vx) cout << p.first << " " << mp[p.first] << endl;
    for (int i = 0; i < m; i++) if (vx[i].first == "crazyzhk") return true;
    return false;
}

string name;
array<int, 3> z1, z2;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> name >> z1[0] >> z1[1] >> z1[2] >> z2[0] >> z2[1] >> z2[2];
        if (name == "crazyzhk") s1 = {name, z1}, s2 = {name, z2};
        else {
            a1.emplace_back(name, z1);
            a2.emplace_back(name, z2);
        }
    }
    cin >> m >> p >> q;
    cnt[0] = n * 0.15, cnt[1] = n * 0.25 + cnt[0], cnt[2] = n * 0.35 + cnt[1];
    tag1[0] = n * 0.25, tag1[1] = n * 0.45, tag1[2] = n * 0.75;
    int ans = 1e9;
    for (int k1 = s1.s[0], tmp; k1 <= 100; k1++) {
        for (int k2 = s2.s[0]; k2 <= 100; k2++) {
            tmp = (k1 - s1.s[0]) * p + (k2 - s2.s[0]) * q;
            Node sx = {s1.name, array{k1, s1.s[1], s1.s[2]}};
            Node sy = {s2.name, array{k2, s2.s[1], s2.s[2]}};
            // if (tmp == 858) {
            //     cout << k1 << ' ' << k2 << endl;
            //     if (check(sx, sy)) ans = min(ans, tmp);
            //     cout << endl;
            // }
            if (tmp < ans && check(sx, sy)) ans = min(ans, tmp);
        }
    }
    if (ans == 1e9) cout << "Surely next time" << endl;
    else cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cout << 100 * 100 * 500 * log2(500) * 10 << endl;
    while (ttt--) Zlin();
    return 0;
}
