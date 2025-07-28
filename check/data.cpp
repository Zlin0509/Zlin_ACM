#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 5;
const int M = 21;
const ll inf = 2e9;
const ll mod = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<int> vi;

vi e[1000];

void generateTree(int n) {
    for (int i = 2; i <= n; i++) {
        int f = rng() % (i - 1) + 1;
        e[f].emplace_back(i);
    }
}

char idx[3]{'L', 'R', 'D'};

void solve() {
    int n = 5, len = 5;
    cout << 1 << endl;
    generateTree(n);
    cout << n << endl;
    for (int i = 0; i < len; i++) cout << idx[rng() % 3];
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << e[i].size() << ' ';
        for (int it: e[i]) cout << it << ' ';
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
