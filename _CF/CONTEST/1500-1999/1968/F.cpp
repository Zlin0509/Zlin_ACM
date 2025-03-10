//
// Created by Zlin on 2024/9/6.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;

int n, q, l, r, x, y;
int a[N], b[N];
map<int, vi> aa;

inline void Zlin() {
    aa.clear();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] xor a[i], aa[b[i]].push_back(i);
    for (int i = 0; i <= n; i++) aa[b[i]].push_back(N);
    while (q--) {
        cin >> l >> r;
        if (!(b[r] xor b[l - 1])) {
            cout << "YES" << '\n';
            continue;
        }
        x = *lower_bound(aa[b[r]].begin(), aa[b[r]].end(), l);
        y = *lower_bound(aa[b[l - 1]].begin(), aa[b[l - 1]].end(), x + 1);
        if (x <= r && y <= r) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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