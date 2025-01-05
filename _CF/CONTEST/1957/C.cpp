//
// Created by Zlin on 2024/9/2.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

const int N = 3e5 + 5;
const ll mo = 1e9 + 7;

ll sum[N];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        if (!a[x])--n;
        ++a[x];
        if (!a[y])--n;
        ++a[y];
    }
    //    cout << n << ' ';
    cout << sum[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    sum[1] = sum[0] = 1;
    for (int i = 2; i <= N - 5; i++)
        sum[i] = (sum[i - 1] + 2 * (i - 1) * sum[i - 2] % mo) % mo;
    while (ttt--) Zlin();
}