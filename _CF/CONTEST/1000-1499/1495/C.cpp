//
// Created by 27682 on 2025/6/21.
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

int n, m;
char mp[501][501];

vi idx[501];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        idx[i].clear();
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'X') idx[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i += 3) {
        for (int j = 1; j <= m; j++) mp[i][j] = 'X';
        if (i + 3 <= n) {
            if (!idx[i + 2].empty()) mp[i + 1][idx[i + 2][0]] = 'X';
            else if (!idx[i + 1].empty()) mp[i + 2][idx[i + 1][0]] = 'X';
            else mp[i + 1][1] = mp[i + 2][1] = 'X';
        } else if (i + 2 == n) for (int j: idx[i + 2]) mp[i + 1][j] = 'X';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << mp[i][j];
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
