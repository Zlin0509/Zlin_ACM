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
int dis[210][210];
int n, m, k;
string s;

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = 1e9;
    getline(cin, s);
    while (m--) {
        getline(cin, s);
        int now = 0;
        vi have;
        for (auto it: s) {
            if (it == ' ') {
                have.push_back(now);
                now = 0;
            } else {
                now = now * 10 + it - '0';
            }
        }
        have.push_back(now);
        int l = have[0], r;
        for (int i = 1; i < have.size(); i += 2) {
            r = have[i + 1];
            dis[l][r] = min(dis[l][r], have[i]);
            dis[r][l] = min(dis[r][l], have[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int q = 1; q <= n; q++)
                dis[i][j] = min(dis[i][j], dis[i][q] + dis[q][j]);
    int q;
    cin >> q;
    while (q--) {
        int s;
        cin >> s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
