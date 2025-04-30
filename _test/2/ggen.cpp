//
// Created by Zlin on 2024/12/5.
//

#include "bits/stdc++.h"
#include "testlib.h"

using namespace std;

const int MAXN = 1e9;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int T = 1;
    cout << T << '\n';
    int total = 0;
    while (T--) {
        int n = 200000;
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << rnd.next(1, MAXN);
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}