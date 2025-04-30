//
// Created by Zlin on 2025/4/13.
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
    string s;
    cin >> s;
    s = ' ' + s;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }
    auto check = [&](int x) {
        string a = s;
        int lx = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == '0') continue;
            if (i - lx - 1 > x)
                return false;
            if (i - lx - 1 == x) {
                lx = i + x - 1;
            } else if (i - lx - 1 < x) {
                lx = i + x;
            }
        }
        return lx >= n;
    };
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
