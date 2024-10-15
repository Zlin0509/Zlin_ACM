//
// Created by Zlin on 2024/10/15.
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
    int l = 1, r = 2, z = 0;
    while (!z && r <= n) {
        cout << "? " << l << ' ' << r << '\n';
        cout.flush();
        cin >> z;
        l += 2, r += 2;
    }
    l -= 2, r -= 2;
    if (!z && n & 1) {
        l = n - 1, r = n;
        cout << "? " << l << ' ' << r << '\n';
        cout.flush();
        cin >> z;
    }
    if (!z) {
        cout << "!  1" << '\n';
        cout.flush();
        return;
    }
    if (l > 1) z = l - 1;
    else z = n;
    cout << "? " << l << ' ' << z << '\n';
    cout.flush();
    cin >> z;
    int check = 0;
    if (z) {
        if (l > 2) z = l - 2;
        else z = n - 1;
        cout << "? " << l << ' ' << z << '\n';
        cout.flush();
        cin >> z;
        z ? check = 2 : check = 1;
    } else {
        if (r < n) z = r + 1;
        else z = 1;
        cout << "? " << r << ' ' << z << '\n';
        cout.flush();
        cin >> z;
        if (!z) {
            check = 1;
        } else {
            if (r < n - 1) z = r + 2;
            else z = 2;
            cout << "? " << r << ' ' << z << '\n';
            cout.flush();
            cin >> z;
            z ? check = 2 : check = 1;
        }
    }
    cout << "! " << check << '\n';
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}