//
// Created by Zlin on 2024/12/5.
//

#include "bits/stdc++.h"
#include "testlib.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int main(int argc, char *argv[]) {
    int T = inf.readInt(1, 200000, "T");
    inf.readEoln();
    int total = 0;
    for (int i = 1; i <= T; i++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readEoln();
        total += n;
        if (total > 200000) throw invalid_argument("Too more");
        for (int j = 1; j <= n; j++) {
            inf.readInt(1, 1e9, "a_i");
            if (j < n)inf.readSpace();
        }
        inf.readEoln();
    }
    inf.readEof();
}