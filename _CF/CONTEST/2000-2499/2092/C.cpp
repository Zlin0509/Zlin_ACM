//
// Created by Zlin on 2025/3/29.
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

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;
    sort(a.begin(), a.end());
    stack<int> x, y;
    ll ans = 0;
    for (int it: a) {
        ans = max(ans, (ll) it);
        if (it & 1) {
            x.push(it);
        } else {
            y.push(it);
        }
    }
    ll val = 0;
    if (!x.empty()) {
        val = x.top();
        x.pop();
        if (!y.empty()) {
            while (!y.empty()) {
                val += y.top();
                y.pop();
            }
            while (!x.empty()) {
                val += x.top() - 1;
                x.pop();
            }
        }
    }
    cout << max(ans, val) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
