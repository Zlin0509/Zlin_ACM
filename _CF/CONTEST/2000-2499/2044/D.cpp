//
// Created by Zlin on 2024/12/15.
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
    vi a(n), ans(n), used(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        if (!used[a[i] - 1]) {
            used[a[i] - 1] = 1;
            ans[i] = a[i];
        }
    queue<int> have;
    for (int i = 0; i < n; i++)
        if (!used[i])
            have.push(i + 1);
    for (int i = 0; i < n; i++)
        if (!ans[i]) {
            ans[i] = have.front();
            have.pop();
        }
    for (auto it: ans) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
