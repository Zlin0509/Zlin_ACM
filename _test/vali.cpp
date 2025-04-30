#include "2/testlib.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    // 注册 testlib 库的输入输出文件
    registerValidation(argc, argv);

    // 读取 n, m, x 并验证是否在规定范围内
    int n = inf.readInt(1, 2 * 1e5, "n");
    inf.readSpace();  // 确保空格读取正确
    int m = inf.readInt(1, 2 * 1e5, "m");
    inf.readSpace();  // 确保空格读取正确
    int x = inf.readInt(1, 2 * 1e5, "x");
    inf.readEoln();  // 读取换行，确保行尾换行符

    // 读取数组 a 并验证
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = inf.readInt(1, 2 * 1e5, "a");
        if (i < n - 1) inf.readSpace();  // 读取空格，防止多余空格错误
    }

    inf.readEoln();  // 读取换行符，确保每行结尾有换行

    // 读取数组 b 并验证
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = inf.readInt(1, 2 * 1e5, "b");
        if (i < n - 1) inf.readSpace();  // 读取空格，防止多余空格错误
    }

    inf.readEoln();  // 读取换行符，确保每行结尾有换行

    // 读取策略数据并验证
    vector<pair<int, int>> strategies(x);
    for (int i = 0; i < x; i++) {
        int t_i = inf.readInt(1, 2 * 1e5, "t_i");
        inf.readSpace();  // 读取空格
        int d_i = inf.readInt(1, 2 * 1e5, "d_i");

        // 检查 t_i 和 d_i 是否在规定范围内
        if (t_i < 1 || t_i > 2 * 1e5 || d_i < 1 || d_i > 2 * 1e5) {
            quitf(_pe, "t_i or d_i out of range at strategy %d", i);
        }
        strategies[i] = {t_i, d_i};
        inf.readEoln();  // 读取换行符，确保每行结尾有换行
    }

    inf.readEof(); //读文件结束
    return 0;
}