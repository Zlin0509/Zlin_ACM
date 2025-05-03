#include <bits/stdc++.h>
using namespace std;

// 使用全局的随机数生成器
mt19937_64 rng;

// 返回指定范围内的随机整数
int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main(int argc, char *argv[]) {
    // 参数检查
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " H W M seed\n";
        return 1;
    }

    // 读取命令行参数
    int H = stoi(argv[1]);
    int W = stoi(argv[2]);
    int M = stoi(argv[3]);
    string seed_string = argv[4];

    // 输入范围校验
    if (H <= 0 || W <= 0 || M < 0 || M >= H * 1LL * W) {
        cerr << "Invalid input: make sure H, W > 0 and 0 <= M < H*W\n";
        return 1;
    }

    // 使用 std::hash 将种子字符串转化为一个哈希值（数值）
    hash<string> hash_fn;
    unsigned long long seed = hash_fn(seed_string); // 将字符串转换为一个数值
    // 设置随机数生成器种子
    rng.seed(seed);

    // 输出 H, W 和 M
    cout << H << " " << W << " " << M << '\n';

    // 使用 set 来确保不重复障碍物
    set<pair<int, int> > used;
    used.insert({1, 1}); // 起点 (1,1) 不能是障碍物

    // 随机生成 M 个不同的障碍物位置
    for (int i = 0; i < M;) {
        // 随机选择位置 (x, y)
        int x = randint(1, H);
        int y = randint(1, W);
        pair<int, int> p = {x, y};

        // 如果该位置已经被占用，则跳过
        if (used.count(p)) continue;

        // 否则，将该位置作为障碍物输出
        used.insert(p);
        cout << x << " " << y << '\n';
        ++i; // 成功生成一个障碍物后计数器加 1
    }

    return 0;
}
