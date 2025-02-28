#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef unordered_map<int, int> umap;

void Zlin() {
    int n, m;
    cin >> n >> m;

    vi pizza(n);
    umap freq; // 统计 bitmask 频次
    vector<int> bitmasks; // 存储唯一的 bitmask

    // 读取朋友对比萨的喜好，并转换成 bitmask
    for (int i = 0; i < m; ++i) {
        string s;
        int mask = 0;
        for (char c : s) mask |= (1 << (c - 'A')); // 生成 bitmask
        if (freq[mask]++ == 0) bitmasks.push_back(mask); // 只存唯一 bitmask
    }

    // 读取比萨大小
    for (int &p : pizza) cin >> p;

    int total_slices = accumulate(pizza.begin(), pizza.end(), 0);
    vi res(total_slices + 1, 0); // 确保输出 `∑𝑎𝑖+1` 个数

    int bsize = bitmasks.size();

    // **优化：用 DP 预计算 Monocarp 吃的比萨数**
    unordered_map<int, int> mono_eat_cache; // 记录 bitmask -> Monocarp 吃的比萨数
    for (int mask : bitmasks) {
        int mono_eat = 0;
        for (int p = 0; p < n; ++p) {
            if (!(mask & (1 << p))) mono_eat += pizza[p]; // Monocarp 吃掉
        }
        mono_eat_cache[mask] = mono_eat;
    }

    // **避免 O(bsize²)，改为 O(2^n * n)**
    for (int i = 0; i < bsize; ++i) {
        int mask1 = bitmasks[i], cnt1 = freq[mask1];
        for (int j = i; j < bsize; ++j) {
            int mask2 = bitmasks[j], cnt2 = freq[mask2];

            if (mask1 == mask2 && cnt1 < 2) continue; // 需要至少两个朋友

            int shared = mask1 & mask2; // 共同喜欢的比萨
            bool valid = true;

            // **快速判断是否争吵**
            for (int p = 0; p < n; ++p) {
                if ((shared & (1 << p)) && (pizza[p] % 2)) {
                    valid = false; // 奇数比萨导致争吵
                    break;
                }
            }

            if (valid) {
                int mono_eat = mono_eat_cache[mask1 | mask2]; // 直接取缓存值
                res[mono_eat] += (mask1 == mask2) ? (cnt1 * (cnt1 - 1) / 2) : (cnt1 * cnt2);
            }
        }
    }

    // **输出 `∑𝑎𝑖+1` 个整数**
    for (int i = 0; i <= total_slices; ++i) cout << res[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
    return 0;
}
