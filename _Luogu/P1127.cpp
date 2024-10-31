//
// Created by Zlin on 2024/10/31.
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

const int N = 1010;

struct edge {
    int to, id;
};

vector<edge> e[30];

vi ans;
int n, cnt = 0, f[30], in[30], out[30];
string a[N];

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    --cnt;
    f[fx] = fy;
}

void add(int u, int v, int id) {
    e[u].push_back({v, id});
    out[u]++, in[v]++;
}

bool check_eul() {
    int l = 0, r = 0;
    for (int i = 0; i < 26; i++) {
        if (out[i] - in[i] == 1) l++;
        else if (in[i] - out[i] == 1) r++;
        else if (in[i] != out[i]) return false;
    }
    return (l == 0 && r == 0) || (l == 1 && r == 1);
}

int vis[N];

bool dfs(int u) {
    if (ans.size() == n) return true;
    for (auto it: e[u]) {
        int v = it.to, id = it.id;
        if (vis[id]) continue;
        ans.push_back(id);
        vis[id] = 1;
        if (dfs(v)) return true;
        else ans.pop_back();
        vis[id] = 0;
    }
    return false;
}

inline void Zlin() {
    memset(f, -1, sizeof f);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1, l, r; i <= n; i++) {
        l = a[i].front() - 'a';
        r = a[i].back() - 'a';
        if (f[l] == -1) {
            f[l] = l;
            ++cnt;
        }
        if (f[r] == -1) {
            f[r] = r;
            ++cnt;
        }
        merge(l, r);
        add(l, r, i);
    }
    if (cnt != 1 || !check_eul()) {
        cout << "***";
        return;
    }
    int start = a[1][0] - 'a';
    for (int i = 0; i < 26; i++) if (out[i] - in[i] == 1) start = i;
    dfs(start);
    for (int i = 0; i < ans.size() - 1; i++) cout << a[ans[i]] << '.';
    cout << a[ans.back()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}