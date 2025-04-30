//
// Created by Zlin on 2024/10/19.
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
    int n, cnt = 0;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            ++cnt;
    }
    auto check = [&](int x) {
        int sum = 1, siz = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                sum++;
                siz++;
            } else if (a[i] == -1) {
                siz--;
                if (!siz) return false;
            } else {
                if (x) {
                    --x;
                    sum++;
                    siz++;
                } else {
                    siz--;
                    if (!siz) return false;
                }
            }
        }
        return true;
    };
    int sum = 1, siz = 1, l = 0, r = cnt, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            sum++;
            siz++;
        } else if (a[i] == -1) {
            siz--;
        } else {
            if (l) {
                --l;
                sum++;
                siz++;
            } else {
                siz--;
            }
        }
        if (!siz) {
            cout << -1 << '\n';
            return;
        }
    }
    int z = gcd(sum, siz);
    cout << sum / z << ' ' << siz / z << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}