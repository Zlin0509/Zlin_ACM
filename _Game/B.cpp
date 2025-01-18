//
// Created by Zlin on 2024/11/3.
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

const int MAXN = 200005;

vector<int> adj[MAXN];
int degree[MAXN];
bool visited[MAXN];


void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

inline void Zlin() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        degree[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int count_1 = 0, count_2 = 0;
    for (int i = 0; i < N; ++i) {
        if (degree[i] == 1) count_1++;
        else if (degree[i] == 2) count_2++;
        else {
            cout << "No" << endl;
            return;
        }
    }

    if (count_1 != 2 || count_2 != N - 2) {
        cout << "No" << endl;
        return;
    }

    dfs(0);
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}