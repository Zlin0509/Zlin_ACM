//
// Created by Zlin on 2024/10/18.
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

const ll mo = 998244353;

ll sum[70][2][2][2]{}, f[2][2][2]{}; // 一数字二大写字母三小写字母
int n;
string x;
vi a;

inline void Zlin() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        if (x[i] <= '9' && x[i] >= '0') {
            a.push_back(x[i] - '0');
        } else if (x[i] >= 'a' && x[i] <= 'z') {
            a.push_back(x[i] - 'a' + 10);
        } else if (x[i] >= 'A' && x[i] <= 'Z') {
            a.push_back(x[i] - 'A' + 36);
        } else {
            a.push_back(-1);
        }
    }
    if (a[0] == -1) {
        for (int j = 0; j < 62; j++) {
            if (j < 10) sum[j][1][0][0] = 1;
            else if (j < 36) sum[j][0][0][1] = 1;
            else sum[j][0][1][0] = 1;
        }
    } else if (a[0] < 10) {
        sum[a[0]][1][0][0] = 1;
    } else if (a[0] >= 36) {
        sum[a[0]][0][1][0] = 1;
    } else {
        sum[a[0]][0][0][1] = sum[a[0] + 26][0][1][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int t1 = 0; t1 < 2; t1++) {
            for (int t2 = 0; t2 < 2; t2++) {
                for (int t3 = 0; t3 < 2; t3++) {
                    f[t1][t2][t3] = 0;
                    for (int j = 0; j < 62; j++)
                        f[t1][t2][t3] = (f[t1][t2][t3] + sum[j][t1][t2][t3]) % mo;
                }
            }
        }
        if (a[i] == -1) {
            for (int j = 0; j < 62; j++) {
                for (int t1 = 0; t1 < 2; t1++) {
                    for (int t2 = 0; t2 < 2; t2++) {
                        if (j < 10) {
                            sum[j][1][t1][t2] = (f[1][t1][t2] + f[0][t1][t2] - sum[j][1][t1][t2] + mo) % mo;
                        } else if (j < 36) {
                            sum[j][t1][t2][1] = (f[t1][t2][1] + f[t1][t2][0] - sum[j][t1][t2][1] + mo) % mo;
                        } else {
                            sum[j][t1][1][t2] = (f[t1][1][t2] + f[t1][0][t2] - sum[j][t1][1][t2] + mo) % mo;
                        }
                    }
                }
            }
        } else if (a[i] < 10) {
            for (int t1 = 0; t1 < 2; t1++)
                for (int t2 = 0; t2 < 2; t2++)
                    sum[a[i]][1][t1][t2] = (f[1][t1][t2] + f[0][t1][t2] - sum[a[i]][1][t1][t2] + mo) % mo;
            for (int j = 0; j < 62; j++) {
                if (j == a[i])continue;
                for (int t1 = 0; t1 < 2; t1++)
                    for (int t2 = 0; t2 < 2; t2++)
                        for (int t3 = 0; t3 < 2; t3++)
                            sum[j][t1][t2][t3] = 0;
            }
        } else if (a[i] >= 36) {
            for (int t1 = 0; t1 < 2; t1++)
                for (int t2 = 0; t2 < 2; t2++)
                    sum[a[i]][t1][1][t2] = (f[t1][1][t2] + f[t1][0][t2] - sum[a[i]][t1][1][t2] + mo) % mo;
            for (int j = 0; j < 62; j++) {
                if (j == a[i])continue;
                for (int t1 = 0; t1 < 2; t1++)
                    for (int t2 = 0; t2 < 2; t2++)
                        for (int t3 = 0; t3 < 2; t3++)
                            sum[j][t1][t2][t3] = 0;
            }
        } else {
            for (int t1 = 0; t1 < 2; t1++)
                for (int t2 = 0; t2 < 2; t2++)
                    sum[a[i]][t1][t2][1] = (f[t1][t2][1] + f[t1][t2][0] - sum[a[i]][t1][t2][1] + mo) % mo;
            for (int t1 = 0; t1 < 2; t1++)
                for (int t2 = 0; t2 < 2; t2++)
                    sum[a[i] + 26][t1][1][t2] = (f[t1][1][t2] + f[t1][0][t2] - sum[a[i] + 26][t1][1][t2] + mo) % mo;
            for (int j = 0; j < 62; j++) {
                if (j == a[i] || j == a[i] + 26) continue;
                for (int t1 = 0; t1 < 2; t1++)
                    for (int t2 = 0; t2 < 2; t2++)
                        for (int t3 = 0; t3 < 2; t3++)
                            sum[j][t1][t2][t3] = 0;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j < 62; j++)
        ans = (ans + sum[j][1][1][1]) % mo;
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}