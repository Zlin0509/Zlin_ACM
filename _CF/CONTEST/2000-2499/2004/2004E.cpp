//
// Created by Zlin on 2024/9/10.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int MOD = 998244353;
const int N = 1e7 + 5;

int lp[N + 1];
vector<int> pr;
int idx[N + 1];

void precalc() {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * 1ll * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 0; i < pr.size(); i++)
        idx[pr[i]] = i + 1;
}

int get(int x) {
    if (x == 1) return 1;
    x = lp[x];
    if (x == 2) return 0;
    else return idx[x];
}

inline void Zlin() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        ans ^= get(x);
    }
    cout << (ans ? "Alice" : "Bob") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    precalc();
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}