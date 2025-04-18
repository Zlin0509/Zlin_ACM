//
// Created by Zlin on 2025/1/16.
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

struct node {
    string name, id;
    int val;
    string time;
    int pos;

    bool operator<(const node &x) const {
        int x1 = (time[0] - '0') * 10 + time[1] - '0';
        int x2 = (x.time[0] - '0') * 10 + x.time[1] - '0';
        if (x1 != x2) return x1 < x2;
        x1 = (time[3] - '0') * 10 + time[4] - '0';
        x2 = (x.time[3] - '0') * 10 + x.time[4] - '0';
        if (x1 != x2) return x1 < x2;
        return pos < x.pos;
    }
};

inline void Zlin() {
    int d, p;
    cin >> d >> p;
    unordered_map<string, int> used, tag;
    vector<pair<string, string>> ans;
    for (int i = 1; i <= d; i++) {
        int t, s;
        cin >> t >> s;
        vector<node> a(t);
        for (int j = 0; j < t; j++) {
            cin >> a[j].name >> a[j].id >> a[j].val >> a[j].time;
            a[j].pos = j;
            if (a[j].val == 1 && !tag[a[j].id] && a[j].id.length() == 18) {
                tag[a[j].id] = 1;
                ans.push_back({a[j].name, a[j].id});
            }
        }
        sort(a.begin(), a.end());
        for (auto [name, id, val, time, pos]: a) {
            if (!s)break;
            if (val == 1 && id.length() == 18 && !tag[id]) {
                tag[id] = 1;
                ans.push_back({name, id});
            }
            if (id.length() == 18) {
                if (used[id]) {
                    if (i >= used[id] + p + 1) {
                        --s;
                        used[id] = i;
                        cout << name << ' ' << id << endl;
                    }
                } else {
                    --s;
                    used[id] = i;
                    cout << name << ' ' << id << endl;
                }
            }
        }
    }
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
