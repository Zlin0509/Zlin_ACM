#include <bits/stdc++.h>
using namespace std;

typedef __int128 i128;

// 计算车手的圈速时间
i128 cost(i128 a, i128 b, i128 k) {
    return a * k * (k + 1) / 2 + b * k;
}

// 转换 __int128 为字符串，以便输出
string to_string_i128(i128 x) {
    string result = "";
    if (x < 0) {
        result += '-';
        x = -x;
    }
    while (x) {
        result += char(x % 10 + '0');
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

// 读入 __int128 类型的数字
i128 read_i128() {
    i128 x = 0;
    string s;
    cin >> s;
    bool neg = (s[0] == '-');
    if (neg) s = s.substr(1);  // 去掉负号
    for (char c : s) {
        x = x * 10 + (c - '0');
    }
    return neg ? -x : x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 输入
    i128 n = read_i128();
    i128 a1 = read_i128();
    i128 b1 = read_i128();
    i128 a2 = read_i128();
    i128 b2 = read_i128();

    i128 ans = (i128)1 << 60;  // 初始化为一个大的数

    // 暴力枚举车手 A 跑的圈数 x, 车手 B 跑 n - x 圈
    for (i128 x = 1; x < n; ++x) {
        i128 y = n - x;
        // 计算总时间
        i128 total_cost = cost(a1, b1, x) + cost(a2, b2, y);
        ans = min(ans, total_cost);
    }

    // 输出最小耗时
    cout << to_string_i128(ans) << "\n";

    return 0;
}
