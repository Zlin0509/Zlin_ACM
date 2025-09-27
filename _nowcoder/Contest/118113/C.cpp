//
// Created by 27682 on 2025/9/27.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int ll
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


inline void Zlin() {
    int n, lx[2]{}, rx[2]{};
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        int k = y + x;
        lx[0] = min(lx[0], k), rx[0] = max(rx[0], k);
        k = y - x;
        lx[1] = min(lx[1], k), rx[1] = max(rx[1], k);
        cout << max(rx[1] - lx[1], rx[0] - lx[0]) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
