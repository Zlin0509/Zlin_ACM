//
// Created by Zlin on 2024/9/19.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
int n, m;
ll a[100010]{};


inline void Zlin() {
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], ans = max(ans, a[i]);
    char c;
    int l, r;
    while (m--) {
        cin >> c >> l >> r;
        if (c == '+' && l <= ans && r >= ans) {
            ++ans;
        } else if (c == '-' && l <= ans && r >= ans) {
            --ans;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}