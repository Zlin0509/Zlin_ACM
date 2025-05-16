//
// Created by Zlin on 2025/5/16.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 50;

int n, cnt[N];
vi used;

inline void Zlin() {
    used.push_back(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        if (x > 0) {
            for (int j = 0; j < 40; j++) {
                if (cnt[i + j] == 2) {
                    cnt[i + j + 1] += 1;
                    cnt[i + j] = 0;
                } else if (cnt[i + j] == -1) {
                    cnt[i + j + 1] -= 1;
                    cnt[i + j] = 1;
                }
                if (x >> j & 1) cnt[i + j] += 1;
                if (cnt[i + j] == 2) {
                    cnt[i + j + 1] += 1;
                    cnt[i + j] = 0;
                }
            }
        }
        if (x < 0) {
            x = -x;
            for (int j = 0; j < 40; j++) {
                if (cnt[i + j] == 2) {
                    cnt[i + j + 1] += 1;
                    cnt[i + j] = 0;
                } else if (cnt[i + j] == -1) {
                    cnt[i + j + 1] -= 1;
                    cnt[i + j] = 1;
                }
                if (x >> j & 1) cnt[i + j] -= 1;
                if (cnt[i + j] == -1) {
                    cnt[i + j] = 1;
                    cnt[i + j + 1] -= 1;
                }
            }
        }
        if (cnt[i]) used.push_back(i);
        int val = used.back();
        for (int j = 42; ~j; j--) {
            if (cnt[i + j]) {
                val = i + j;
                break;
            }
        }
        if (cnt[val] > 0) cout << '+';
        else if (cnt[val] < 0) cout << '-';
        else cout << '0';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
