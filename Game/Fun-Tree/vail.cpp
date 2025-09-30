#include "testlib.h"
#include <set>
#include <utility>
using namespace std;

int main() {
    registerValidation();

    int n = inf.readInt(2, 200000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 200000, "m");
    inf.readSpace();
    int q = inf.readInt(1, 200000, "q");
    inf.readEoln();

    set<pair<int, int> > edges;

    for (int i = 0; i < m; i++) {
        int u = inf.readInt(1, n, "u");
        inf.readSpace();
        int v = inf.readInt(1, n, "v");
        inf.readEoln();
        ensuref(u != v, "Edge #%d is a self-loop: (%d, %d)", i + 1, u, v);
        if (u > v) swap(u, v);
        ensuref(!edges.count({u, v}), "Duplicate edge found: (%d, %d)", u, v);
        edges.insert({u, v});
    }

    for (int i = 0; i < q; i++) {
        int x = inf.readInt(1, n, "x");
        inf.readSpace();
        int y = inf.readInt(1, n, "y");
        inf.readEoln();
        ensuref(x != y, "Query #%d has identical points: (%d, %d)", i + 1, x, y);
    }

    inf.readEof();
}
