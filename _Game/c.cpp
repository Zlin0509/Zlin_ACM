//
// Created by Zlin on 2025/6/8.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, k;

vector<int> primes; // 存储所有质数
bool is_prime[100000001]; // 标记是否为质数

void linearSieve(int n) {
    // 初始化
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i); // 如果i是质数，加入质数列表
        }

        // 筛选合数
        for (int p: primes) {
            if (i * p > n) break; // 超过范围，停止
            is_prime[i * p] = false; // 标记i * p为合数

            // 如果i能被p整除，停止当前质数的筛选
            if (i % p == 0) break;
        }
    }
}

int l[200010];

inline void Zlin() {
    linearSieve(2e7);
    cin >> n >> k;
    vll ans;
    for (int i = 0; i <= k; i++) l[i] = i;
    while (ans.size() < n) {
        for (int i = 0; i <= k && ans.size() < n; i++) {
            ans.push_back(1ll * primes[l[i]] * primes[i]);
            l[i] += k + 1;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
