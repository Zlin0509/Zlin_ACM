//
// Created by Zlin on 2024/8/17.
//
#include "bits/stdc++.h"

using namespace std;

inline void Zlin() {
    int l = 1, r = 999;
    while (r - l > 2) {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        cout << "? " << a << ' ' << b << endl;
        int resp; cin >> resp;

        if (resp == (a + 1) * (b + 1)) {
            r = a;
        }
        else if (resp == a * b) {
            l = b;
        }
        else {
            l = a; r = b;
        }
    }
    if (r - l == 2) {
        cout << "? 1 " << l + 1 << endl;
        int resp; cin >> resp;

        if (resp == l + 1) {l = l + 1;}
        else {r = l + 1;}

    }
    cout << "! " << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--)Zlin();
}