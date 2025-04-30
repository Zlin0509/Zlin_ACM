//
// Created by Zlin on 2024/9/20.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i >= k; i--) cout << i << ' ';
    for (int i = m + 1; i < k; i++) cout << i << ' ';
    for (int i = 1; i <= m; i++) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}