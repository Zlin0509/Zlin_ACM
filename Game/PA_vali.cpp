#include "testlib.h"

int main() {
    registerValidation();

    int T = inf.readInt(1, 2e5, "T");
    inf.readEoln();

    for (int t = 0; t < T; ++t) {
        int n = inf.readInt(2, 1e9, "n");
        inf.readSpace();
        int a1 = inf.readInt(1, 1e5, "a1");
        inf.readSpace();
        int b1 = inf.readInt(1, 1e5, "b1");
        inf.readSpace();
        int a2 = inf.readInt(1, 1e5, "a2");
        inf.readSpace();
        int b2 = inf.readInt(1, 1e5, "b2");
        inf.readEoln();
    }

    inf.readEof();
}
