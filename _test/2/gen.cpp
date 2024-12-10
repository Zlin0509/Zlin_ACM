//
// Created by Zlin on 2024/12/5.
//

#include "bits/stdc++.h"
#include "testlib.h"

using namespace std;

const int MAXN = 1e9;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int T = opt<int>("T");
    cout << T << '\n';
    int total = 0;
    while (T--) {
        int mm = 200000 - total;
        int n = rnd.next(1, min(mm, 200000));
        total += n;
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << rnd.next(1, MAXN);
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}