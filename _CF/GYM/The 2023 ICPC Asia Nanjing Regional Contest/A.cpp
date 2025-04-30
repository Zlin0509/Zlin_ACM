//
// Created by Zlin on 2024/10/13.
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

const int N = 1e3 + 5;

int n, m;
char a[N][N];
int vis[N * N];
bool flag[N * N];
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

int gao(int i, int j, int r, int c) {
    return
            i * m * n * m +
            j * n * m +
            r * m +
            c;
}

void ugao(int tag, int &i, int &j, int &r, int &c) {
    i = tag / (m * n * m);
    j = tag / (n * m) % m;
    r = tag / m % n;
    c = tag % m;
}

bool cal(int i, int j) {
    return a[i][j] == 'O' || i < 0 || i >= n || j < 0 || j >= m;
}

void bfs(int tag) {
    queue<int> q;
    q.push(tag);
    vis[tag] = tag;
    flag[tag] = false;

    int i, j, r, c;
    int ii, jj, rr, cc;

    while (!q.empty()) {
        ugao(q.front(), i, j, r, c);
        q.pop();
        for (int k = 0; k < 4; k++) {
            ii = i + dx[k], rr = r + dx[k];
            jj = j + dy[k], cc = c + dy[k];
            if (cal(ii, jj))continue;
            if (cal(rr, cc)) {
                flag[tag] = true;
                continue;
            }
            int v = gao(ii, jj, rr, cc);
            if (vis[v] >= 0) continue;
            q.push(v);
            vis[v] = tag;
        }
    }
}

int check(int i, int j) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (a[r][c] == 'O' || (r == i && c == j)) continue;
            int tag = gao(i, j, r, c);
            if (vis[tag] == -1) bfs(tag);
            if (!flag[vis[tag]]) return 0;
        }
    }
    return 1;
}

inline void Zlin() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    memset(vis, -1, sizeof(int) * (n * m * n * m + 3));

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.')
                ans += check(i, j);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}