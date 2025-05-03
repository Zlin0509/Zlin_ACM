//
// Created by 27682 on 2025/5/3.
//
#include <bits/stdc++.h>
using namespace std;

// 使用字符串种子生成哈希作为随机种子
uint64_t hash_seed(const string &s) {
    uint64_t h = 0xcbf29ce484222325;
    for (char c: s) {
        h ^= uint64_t(c);
        h *= 0x100000001b3;
    }
    return h;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <N> <K> <seed_string>\n";
        return 1;
    }

    int N = stoi(argv[1]);
    int K = stoi(argv[2]);
    string seed_str = argv[3];

    if (K < 1 || K > N || N <= 0) {
        cerr << "Invalid parameters: ensure 1 <= K <= N and N > 0.\n";
        return 1;
    }

    // 将字符串转为 hash 用于初始化随机数生成器
    uint64_t seed = hash_seed(seed_str);
    mt19937_64 rng(seed);

    uniform_int_distribution<int> type_dist(1, N);
    uniform_int_distribution<int> taste_dist(1, 1'000'000'000);

    cout << N << " " << K << '\n';
    for (int i = 0; i < N; ++i) {
        int t = type_dist(rng);
        int d = taste_dist(rng);
        cout << t << " " << d << '\n';
    }

    return 0;
}
