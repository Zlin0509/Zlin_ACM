//
// Created by 27682 on 2025/4/22.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n), b(n);
    bool tag1 = false, tag2 = false;
    int tag = -1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        if (a[i]) tag1 = true;
        if (a[i] && tag == -1) tag = i;
    }
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        b[i] = c - '0';
        if (b[i]) tag2 = true;
    }
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (tag1 != tag2) {
        cout << -1 << endl;
        return;
    }
    int lx = n + 2, rx = -1;
    for (int i = 0; i < n; i++) {
        if (b[i]) {
            lx = min(lx, i);
            rx = max(rx, i);
        }
    }
    vi op;
    for (int i = lx; i <= rx; i++) {
        if (a[i] == b[i]) continue;
        op.push_back(tag - i);
        vi now;
        for (int j = tag; j < n; j++) now.push_back(a[j]);
        for (int j = 0; j < now.size() && i + j < n; j++) a[i + j] ^= now[j];
        for (int j = 0; j < n; j++) {
            if (a[j]) {
                tag = j;
                break;
            }
        }
    }
    for (int i = rx + 1; i < n; i++) {
        if (a[i] == b[i]) continue;
        op.push_back(tag - i);
        vi now;
        for (int j = tag; j < n; j++) now.push_back(a[j]);
        for (int j = 0; j < now.size() && i + j < n; j++) a[i + j] ^= now[j];
        for (int j = 0; j < n; j++) {
            if (a[j]) {
                tag = j;
                break;
            }
        }
    }
    for (int j = n - 1; ~j; j--) {
        if (a[j]) {
            tag = j;
            break;
        }
    }
    for (int i = lx - 1; ~i; i--) {
        if (a[i] == b[i]) continue;
        op.push_back(tag - i);
        vi now;
        for (int j = tag; ~j; j--) now.push_back(a[j]);
        for (int j = 0; j < now.size() && i - j >= 0; j++) a[i - j] ^= now[j];
        for (int j = n - 1; ~j; j--) {
            if (a[j]) {
                tag = j;
                break;
            }
        }
    }
    cout << op.size() << endl;
    for (int it: op) cout << it << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
