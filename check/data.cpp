#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 21;
const ll inf = 2e9;
const ll mod = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int ttt = rng() % 20000 + 1;
    cout << ttt << endl;
    while (ttt--) {
        for (int i = 1; i <= 5; i++) cout << rng() % 10000 << ' ';
        for (int i = 6; i <= 13; i++) cout << rng() % 10000 << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
