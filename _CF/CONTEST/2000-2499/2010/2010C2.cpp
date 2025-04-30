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

const int N = 4e5 + 5;

string x;
int n;
ll base = 1154123, mo = 1333121;
ll ha[N], dep[N];

inline void Zlin() {
    cin >> x;
    n = x.length();
    x = ' ' + x;
    dep[0] = 1;
    for (int i = 1; i <= n; i++)dep[i] = dep[i - 1] * base % mo;
    for (int i = 1; i <= n; i++)ha[i] = (ha[i - 1] * base + x[i]) % mo;
    int l = 1, r = n, llx, rrx;
    ll lx, rx, mx;
    bool check = true;
    while (l < r) {
        lx = ha[l];
        rx = (ha[n] - ha[r - 1] * dep[n - r + 1] % mo + mo) % mo;
        if (lx == rx) {
            rrx = (n + l) / 2;
            llx = rrx - l + 1;
            mx = (ha[rrx] - ha[llx - 1] * dep[rrx - llx + 1] % mo + mo) % mo;
            if (mx == lx) {
                lx = ha[rrx];
                rx = (ha[n] - ha[llx - 1] * dep[n - llx + 1] % mo + mo) % mo;
                if (lx == rx) {
                    check = false;
                    break;
                }
            }
        }
        ++l;
        --r;
    }
    if (check) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= (n + l) / 2; i++) cout << x[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
}