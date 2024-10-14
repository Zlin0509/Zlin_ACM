//
// Created by Zlin on 2024/10/14.
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

const int N = 1100;

int n, m;
vector<string> have;
string a[N], b[N];
vector<string> aa[N], bb[N];
map<string, int> to;

int ch[N][N], idx, tag[N];
vi nxt[N];

void insert(vector<string> s) {
    int p = 0;
    for (auto it: s) {
        int j = to[it];
        if (!ch[p][j]) {
            ch[p][j] = ++idx;
            nxt[p].push_back(idx);
        }
        p = ch[p][j];
    }
}

void down(vector<string> s) {
    int p = 0;
    for (auto it: s) {
        int j = to[it];
        p = ch[p][j];
        tag[p] = 1;
    }
}

int cal(int p) {
    int ans = 0;
    for (auto it: nxt[p]) {
        if (!tag[it]) ans += 1;
        else ans += cal(it);
    }
    return ans;
}

inline void Zlin() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) a[i].clear(), aa[i].clear();
    for (int i = 1; i <= m; i++) b[i].clear(), bb[i].clear();
    for (int i = 0; i <= idx; i++) {
        nxt[i].clear();
        tag[i] = 0;
        memset(ch[i], 0, sizeof ch[i]);
    }
    idx = 0;

    string x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (auto s: a[i]) {
            if (s == '/') {
                aa[i].push_back(x);
                have.push_back(x);
                x.clear();
            } else {
                x += s;
            }
        }
        aa[i].push_back(x);
        have.push_back(x);
        x.clear();
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        for (auto s: b[i]) {
            if (s == '/') {
                bb[i].push_back(x);
                have.push_back(x);
                x.clear();
            } else {
                x += s;
            }
        }
        x.clear();
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    for (int i = 0; i < have.size(); i++)
        to[have[i]] = i + 1;
    for (int i = 1; i <= n; i++)
        insert(aa[i]);
    for (int i = 1; i <= m; i++)
        down(bb[i]);
    cout << cal(0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}