//
// Created by 27682 on 2025/5/10.
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

int A[1005][1005], B[1005][1005];
int a[1005][1005], b[1005][1005];
int n, m;

inline void opa() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

inline void opb() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

vi e[2010];
int used[2010], vis[2010];

bool dfs(int u) {
    vis[u] = 1;
    for (int v: e[u]) {
        if (vis[v] == 0) {
            if (dfs(v)) return true;
        } else if (vis[v] == 1) return true;
    }
    vis[u] = 2;
    return false;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> B[i][j];
        }
    }
    for (int k = 0; k < 32; k++) {
        for (int i = 1; i <= n + m; i++) {
            used[i] = vis[i] = 0;
            e[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = A[i][j] >> k & 1;
                b[i][j] = B[i][j] >> k & 1;
            }
        }
        // cout << k << endl;
        // opa(), opb();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (b[i][j]) {
                    e[i].push_back(i + j);
                }
                if (!b[i][j]) {
                    e[i + j].push_back(i);
                }
                if (a[i][j] != b[i][j]) {
                    b[i][j] ? used[i + j] = 1 : used[i] = 1;
                }
            }
        }
        for (int i = 1; i <= n + m; i++) {
            if (used[i] && !vis[i] && dfs(i)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
