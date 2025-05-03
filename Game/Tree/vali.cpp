//
// Created by 27682 on 2025/5/3.
//
#include "testlib.h"
#include <set>
#include <utility>

using namespace std;

int main() {
    registerValidation();

    int H = inf.readInt(1, 200000, "H");
    inf.readSpace();
    int W = inf.readInt(1, 200000, "W");
    inf.readSpace();
    int M = inf.readInt(0, 200000, "M");
    inf.readEoln();

    set<pair<int, int> > seen;
    seen.insert({1, 1}); // 起点不能是障碍物

    for (int i = 0; i < M; ++i) {
        int x = inf.readInt(1, H, "X");
        inf.readSpace();
        int y = inf.readInt(1, W, "Y");
        inf.readEoln();

        ensuref(x != 1 || y != 1, "Obstacle cannot be at the start point (1,1)");
        ensuref(seen.insert({x, y}).second, "Duplicate obstacle position (%d,%d)", x, y);
    }

    inf.readEof();
}
