//
// Created by Zlin on 2024/12/9.
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

const int N = 2e5 + 5;

char s[3]{'q', 'k', 'j'};

inline void Zlin() {
    int n;
    cin >> n;
    vector<vi> p(3, vector<int>(n + 5));
    vi mins(3, n);
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> p[i][j];
    vector<pii> ans, sol(n + 1, {-1, 0});
    for (int i = n - 1, check; i >= 1; i--) {
        check = -1;
        for (int j = 0; j < 3; j++) if (p[j][i] > p[j][mins[j]]) check = j;
        if (check == -1) continue;
        sol[i] = {check, mins[check]};
        for (int j = 0; j < 3; j++) if (p[j][i] < p[j][mins[j]]) mins[j] = i;
    }
    if (sol[1] == pii{-1, 0}) {
        cout << "NO" << '\n';
        return;
    }
    ans.push_back(sol[1]);
    while (ans.back().second) ans.push_back(sol[ans.back().second]);
    ans.pop_back();
    cout << "YES" << '\n' << ans.size() << '\n';
    for (auto [x, y]: ans) cout << s[x] << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}