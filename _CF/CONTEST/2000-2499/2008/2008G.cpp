//
// Created by Zlin on 2024/9/24.
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
int n, k, dif;
int a[N];

bool check(int x) {
    int y = x - k + 1, cnt = min((x - 1) / dif + 1, n);
    return cnt >= y;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << (a[1] < k ? k : k - 1) << '\n';
        return;
    }
    sort(a + 1, a + 1 + n);
    dif = a[1];
    for (int i = 1; i <= n; i++) dif = gcd(dif, a[i]);
    int l = 0, r = n + k, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}