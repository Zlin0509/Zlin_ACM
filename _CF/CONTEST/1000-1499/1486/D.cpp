//
// Created by 27682 on 2025/2/26.
//

#include "bits/stdc++.h"

#define endl '\n'
#define lowbit(x) (x&(-x))
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto check = [&](int x) {
        vi sum(n + 1), mm(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + (a[i] < x ? 1 : -1);
            mm[i] = max(mm[i - 1], sum[i]);
        }
        for (int i = k; i <= n; i++)
            if (sum[i] - mm[i - k] < 0)
                return true;
        return false;
    };
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}