//
// Created by 27682 on 2025/5/3.
//
#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int N = 1e5 + 10;

struct Node {
    int t; // type
    int d; // delicious
    bool operator <(const Node &D) const // 按美味值从大到小排序
    {
        return d > D.d;
    }
} a[N];

int n, m, x, y, res;
int types[N]; // types[i] 表示第 i 种寿司有多少杯

signed main() {
    // 读入
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int t, d;
        cin >> t >> d;
        a[i] = {t, d};
    }

    sort(a + 1, a + n + 1); // 按美味值从大到小排序

    for (int i = 1; i <= m; i++) // 先处理前 m 个寿司
    {
        if (!types[a[i].t]) y++; // 如果没有出现过这个种类的寿司，种类数加 1
        types[a[i].t]++; // 这种种类的寿司数加 1
        x += a[i].d; // 总美味值加上了当前寿司的美味值
    }

    res = x + y * y; // 初始答案
    int k = m;

    for (int i = m + 1; i <= n && k; i++) {
        if (types[a[i].t]) continue; // 如果这个种类前面出现过，就不应该继续处理
        types[a[i].t]++, x += a[i].d; // 这个种类数量加 1，总美味值加上当前的美味值
        while (types[a[k].t] <= 1 && k) k--; // 从后向前找到第一个数量出现多次（≥ 2 次）的
        if (!k) break; // 如果不存在出现多次的，退出
        y++, x -= a[k].d, k--; // 种类加 1，总美味值减去出现多次的寿司的美味值，并在以后只需要在前 k - 1 个寿司中寻找
        res = max(res, x + y * y); // 尝试更新答案
    }

    cout << res; // 输出

    return 0;
}
