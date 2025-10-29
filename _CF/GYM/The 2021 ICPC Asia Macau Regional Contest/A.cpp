//
// Created by 27682 on 2025/10/29.
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

constexpr int N = 1e5 + 10;

int n;

struct Node {
    string name;
    int id, time, status;
} a[N];

int tick;
map<string, int> mp;

int acp[N][26], cnt[N][26], fir[N][26];
int cnt1[N][26], acp1[N][26];

struct All {
    string name;
    int num, pant;

    bool operator<(const All &o) const {
        if (num != o.num) return num > o.num;
        return pant < o.pant;
    }

    bool operator==(const All &o) const {
        return num == o.num && pant == o.pant;
    }

    bool operator<=(const All &o) const {
        if (*this < o) return true;
        return *this == o;
    }
};

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        fill(acp[i], acp[i] + 26, -1),
                fill(acp1[i], acp1[i] + 26, -1),
                fill(cnt[i], cnt[i] + 26, 0),
                fill(cnt1[i], cnt1[i] + 26, 0),
                fill(fir[i], fir[i] + 26, -1);
    mp.clear(), tick = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i].name = s;
        char c;
        cin >> c;
        a[i].id = c - 'A';
        int t;
        cin >> t;
        a[i].time = t;
        cin >> s;
        a[i].status = s == "accepted";
        if (!mp.contains(a[i].name)) mp[a[i].name] = ++tick;
    }
    for (int i = 0, id; i < n; i++) {
        id = mp[a[i].name];
        if (a[i].status) {
            if (acp[id][a[i].id] == -1) {
                acp[id][a[i].id] = a[i].time;
            } else if (acp1[id][a[i].id] == -1) {
                acp1[id][a[i].id] = a[i].time;
            }
        } else {
            if (fir[id][a[i].id] == -1) fir[id][a[i].id] = a[i].time;
            if (acp[id][a[i].id] == -1) ++cnt[id][a[i].id];
            else if (acp[id][a[i].id] == -1) ++cnt1[id][a[i].id];
        }
    }
    vector<All> all;
    for (const auto &[name, id]: mp) {
        int num = 0, pant = 0;
        for (int i = 0; i < 26; i++) {
            if (acp[id][i] != -1) {
                ++num;
                pant += acp[id][i] + cnt[id][i] * 20;
            }
        }
        all.emplace_back(name, num, pant);
    }
    sort(all.begin(), all.end());
    n = all.size();
    int m = 0;
    for (int i = 0; i < n; i++) if (all[i].num) ++m;
    int m1 = m + 1;
    int tag = min(34, m / 10 + (m % 10 > 0) - 1);
    int tag1 = min(34, m1 / 10 + (m1 % 10 > 0) - 1);
    while (tag + 1 < n && all[tag] == all[tag + 1]) ++tag;
    while (tag1 + 1 < n && all[tag1] == all[tag1 + 1]) ++tag1;
    vector<string> ans;
    bool check = false;
    for (int i = 0; i < n; i++) {
        if (all[i] <= all[tag]) ans.emplace_back(all[i].name);
        else {
            int id = mp[all[i].name];
            for (int j = 0; j < 26; j++) {
                if (fir[id][j] != -1) {
                    if (acp[id][j] == -1) {
                        if (!all[i].num) {
                            ++all[i].num;
                            all[i].pant += fir[id][j];
                            if (all[i] <= all[tag1]) {
                                ans.emplace_back(all[i].name);
                                if (all[i] == all[tag1]) check = true;
                            }
                            --all[i].num;
                            all[i].pant -= fir[id][j];
                        } else {
                            ++all[i].num;
                            all[i].pant += fir[id][j];
                            if (all[i] <= all[tag]) {
                                ans.emplace_back(all[i].name);
                                if (all[i] == all[tag1]) check = true;
                            }
                            --all[i].num;
                            all[i].pant -= fir[id][j];
                        }
                    } else {
                        all[i].pant += fir[id][j] - acp[id][j];
                        if (all[i] <= all[tag]) {
                            ans.emplace_back(all[i].name);
                            if (all[i] == all[tag1]) check = true;
                        }
                        all[i].pant -= fir[id][j] - acp[id][j];
                    }
                }
            }
        }
    }
    if (check) for (int i = 0; i <= tag1; i++) ans.emplace_back(all[i].name);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if (tag != n - 1) {
        bool check = false;
        for (int i = 0, id; i <= tag; i++) {
            id = mp[all[i].name];
            for (int j = 0; j < 26; j++) {
                if (acp[id][j] == -1) continue;
                if (acp1[id][j] == -1) {
                    --all[i].num;
                    all[i].pant -= acp[id][j];
                    if (all[tag + 1] <= all[i]) {
                        check = true;
                    }
                    ++all[i].num;
                    all[i].pant += acp[id][j];
                } else {
                    all[i].pant += acp1[id][j] - acp[id][j] + cnt1[id][j] * 20;
                    if (all[tag + 1] <= all[i]) {
                        check = true;
                    }
                    all[i].pant -= acp1[id][j] - acp[id][j] + cnt1[id][j] * 20;
                }
            }
        }
        if (check) {
            ++tag;
            while (tag < n) {
                ans.emplace_back(all[tag].name);
                if (tag + 1 >= n || all[tag + 1] != all[tag]) break;
                ++tag;
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    for (const auto &it: ans) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
