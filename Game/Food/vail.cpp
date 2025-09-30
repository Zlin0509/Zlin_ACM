#include "testlib.h"
using namespace std;

int main() {
    registerValidation();

    // 读取 n 和 k
    int n = inf.readInt(1, 200000, "n");
    inf.readSpace();
    int k = inf.readInt(1, n, "k");
    inf.readEoln();

    const long long MAX_NUTRITION = 1000000000000000000LL;

    // 读取 n 个食物的营养值
    for (int i = 0; i < n; i++) {
        long long a = inf.readLong(1, MAX_NUTRITION, "a");
        inf.readSpace();
        long long b = inf.readLong(1, MAX_NUTRITION, "b");
        inf.readSpace();
        long long c = inf.readLong(1, MAX_NUTRITION, "c");
        inf.readEoln();
    }

    inf.readEof();
}
