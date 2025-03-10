//
// Created by Zlin on 2024/10/29.
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

const int N = 510;
int n, s[3][N];

vi e[N << 1];
int dfn[N << 1], low[N << 1], tot;
int stk[N << 1], instk[N << 1], top;
int scc[N << 1], cnt;

inline void tarjan(int x) {
// 入X点，盖时间戳，入栈
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y])
            low[x] = min(low[x], dfn[y]);
    }
// X为强连通图的根,输出分量图
    if (dfn[x] == low[x]) {
        int y;
        ++cnt;
        do {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
        } while (y != x);
    }
}

void init() {
    for (int i = 1; i <= n * 2; i++) {
        e[i].clear();
        cnt = tot = scc[i] = dfn[i] = low[i] = scc[i] = stk[i] = instk[i] = 0;
    }
}

inline void Zlin() {
    cin >> n;
    init();
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    for (int i = 1, a, b; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                a = s[j][i], b = s[k][i];
                if (a < 0 && b < 0) e[-a].push_back(-b + n);
                if (a < 0 && b > 0) e[-a].push_back(b);
                if (a > 0 && b < 0) e[a + n].push_back(-b + n);
                if (a > 0 && b > 0) e[a + n].push_back(b);
            }
        }
    }
    for (int i = 1; i <= n * 2; i++) if (!dfn[i]) tarjan(i);
    bool check = true;
    for (int i = 1; i <= n; i++)
        if (scc[i] == scc[i + n]) {
            check = false;
            break;
        }
    cout << (check ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}