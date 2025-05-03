//
// Created by 27682 on 2025/5/3.
//
#include "testlib.h"
using namespace std;

int main() {
    registerValidation();

    int N = inf.readInt(1, 100000, "N");
    inf.readSpace();
    int K = inf.readInt(1, N, "K");
    inf.readEoln();

    for (int i = 0; i < N; ++i) {
        int t = inf.readInt(1, N, "t_i");
        inf.readSpace();
        int d = inf.readInt(1, 1000000000, "d_i");
        inf.readEoln();
    }

    inf.readEof();
}
