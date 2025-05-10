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

int A[1001][1001], B[1001][1001];
int a[1001][1001], b[1001][1001];
int sum[1001], used[1001];
int n, m;

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
    bool check = true;
    for (int k = 0; k < 32; k++) {
        for (int j = 1; j <= m; j++) sum[j] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = A[i][j] >> k & 1;
                b[i][j] = B[i][j] >> k & 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            // 全零直接跳过
            bool tag = true;
            for (int j = 1; j <= m; j++) {
                if (b[i][j]) {
                    tag = false;
                    break;
                }
            }
            if (tag) {
                for (int j = 1; j <= m; j++) ++sum[j];
                continue;
            }
            // 判断是否需要先&0
            tag = true;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] | used[j] && !b[i][j]) {
                    tag = false;
                    break;
                }
            }
            // 想要进行|1操作必须前面位置全为1
            for (int j = 1; j <= m; j++) {
                if (a[i][j] | used[j] & tag == b[i][j]) {
                    sum[j] += b[i][j];
                    continue;
                }
                if (sum[j] != i - 1) {
                    check = false;
                    break;
                }
                sum[j]++;
                a[i][j] = 1;
                used[j] = 1;
            }
            if (!check) break;
        }
        if (!check) break;
    }
    if (check) {
        cout << "Yes" << endl;
        return;
    }
    check = true;
    for (int k = 0; k < 32; k++) {
        for (int j = 1; j <= m; j++) sum[j] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = A[i][m - j + 1] >> k & 1;
                b[i][j] = B[i][m - j + 1] >> k & 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            // 全零直接跳过
            bool tag = true;
            for (int j = 1; j <= m; j++) {
                if (b[i][j]) {
                    tag = false;
                    break;
                }
            }
            if (tag) {
                for (int j = 1; j <= m; j++) ++sum[j];
                continue;
            }
            // 判断是否需要先&0
            tag = true;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] | used[j] && !b[i][j]) {
                    tag = false;
                    break;
                }
            }
            // 想要进行|1操作必须前面位置全为1
            for (int j = 1; j <= m; j++) {
                if (a[i][j] | used[j] & tag == b[i][j]) {
                    sum[j] += b[i][j];
                    continue;
                }
                if (sum[j] != i - 1) {
                    check = false;
                    break;
                }
                sum[j]++;
                a[i][j] = 1;
                used[j] = 1;
            }
            if (!check) break;
        }
        if (!check) break;
    }
    if (check) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
