#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// **计算单个三角形的最大得分**
ll maxSingleTriangle(vector<int>& a) {
    int n = a.size();
    sort(a.rbegin(), a.rend()); // 降序排序
    return 1LL * a[0] * a[1] * a[2];  // 取前三个最大数的乘积
}

// **计算多个不相交三角形的最大得分**
ll maxMultipleTriangles(vector<int>& a) {
    int n = a.size();
    vector<int> b = a;
    b.insert(b.end(), a.begin(), a.end()); // 复制一遍数组，模拟环形

    ll maxScore = 0;

    // **前缀和优化计算**
    vector<ll> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + b[i - 1]; // 计算前缀和
    }

    // 遍历所有可能的起点
    for (int start = 0; start < n; ++start) {
        for (int k = 1; 3 * k <= n; ++k) { // 尝试不同数量的三角形
            int end = start + 3 * k;
            if (end > start + n) break; // 确保不超出边界

            // 计算 k 组相邻三角形的乘积和
            ll sumScore = 0;
            for (int i = start; i < end; i += 3) {
                sumScore += 1LL * b[i] * b[i + 1] * b[i + 2];
            }

            maxScore = max(maxScore, sumScore);
        }
    }

    return maxScore;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        ll result = max(maxSingleTriangle(a), maxMultipleTriangles(a));
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}