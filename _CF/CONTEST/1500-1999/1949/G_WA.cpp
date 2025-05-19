//
// Created by 27682 on 2025/5/14.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2010;

vi e[N], ans;
int vis[N];

inline void dfs(int u) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (vis[v]) continue;
        dfs(v);
        break;
    }
    ans.push_back(u);
}

struct Op {
    string l;
    int r;
};

vector<Op> op;

inline void Zlin() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (b[i] == '-' || a[i] == b[i]) continue;
        for (int j = 0; j < n; j++) {
            if (a[j] == b[j] || i == j) continue;
            if (a[j] == b[i]) {
                e[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == '-' && b[i] != '-' && !vis[i]) {
            ans.clear();
            dfs(i);
            reverse(ans.begin(), ans.end());
            if (ans.size() > 1) {
                Op tmp;
                tmp = {"DRIVE", ans[0] + 1};
                op.push_back(tmp);
                tmp = {"PICKUP", 0};
                op.push_back(tmp);
                for (int j = 1; j < ans.size(); j++) {
                    tmp = {"DRIVE", ans[j] + 1};
                    op.push_back(tmp);
                    tmp = {"DROPOFF", 0};
                    op.push_back(tmp);
                    if (j != ans.size() - 1) {
                        tmp = {"PICKUP", 0};
                        op.push_back(tmp);
                    }
                }
            }
        }
    }
    cout << op.size() << endl;
    for (auto [l, r]: op) {
        cout << l;
        if (r) cout << ' ' << r;
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}