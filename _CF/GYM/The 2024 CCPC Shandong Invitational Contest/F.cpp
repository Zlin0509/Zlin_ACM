//
// Created by Zlin on 2024/10/7.
//

#include "bits/stdc++.h"

using namespace std;

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
    vll a(n + 1), b(n + 1);
    vll ans(n + 1, 0);
    priority_queue<ll> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b[n] = a[n];
    for (int i = n - 1; i; i--) b[i] = b[i + 1] + a[i];
    for (int i = 2; i <= n; i++) q.push(b[i]);
    ans[1] = b[1];
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] + q.top();
        q.pop();
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}