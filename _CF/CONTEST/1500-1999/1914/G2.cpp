//
// Created by Zlin on 2024/10/30.
//

#include "bits/stdc++.h"
#include <random>
#include <chrono>

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
const int mo = 998244353;

mt19937_64 rng(98275314);

int n, c[N << 1];
ll ans1, ans2;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n * 2; i++) cin >> c[i];
    vector<ull> val(n + 1);
    vi End(n * 2 + 2, 0);
    unordered_map<ull, int> used;
    for (int i = 1; i <= n; i++) val[i] = rng();
    ull now = 0;
    used[0] = 1;
    ans1 = 0, ans2 = 1;
    auto cal = [&](int l, int r) {
        int res = 0;
        while (l <= r) {
            if (End[l] && End[l] <= r) {
                l = End[l];
            } else {
                ++res;
                ++l;
            }
        }
        return res;
    };
    for (int i = 1; i <= n * 2; i++) {
        now ^= val[c[i]];
        if (now == 0) {
            ++ans1;
            ans2 = ans2 * cal(used[now], i) % mo;
            used.clear();
        } else if (used[now]) {
            End[used[now]] = i + 1;
        }
        used[now] = i + 1;
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}