//
// Created by Zlin on 2024/10/17.
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

const int N = 1e6;
int cnt[N];

inline void Zlin() {
    int n;
    cin >> n;
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        cnt[i]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (cnt[i] == 1)++ans;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    cout << ans - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}