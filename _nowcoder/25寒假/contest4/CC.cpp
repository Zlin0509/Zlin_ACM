//
// Created by Zlin on 2025/2/6.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin()
{
    ll n;
    string s;
    cin >> n >> s;

    ll count_01 = 0, count_10 = 0, question_count = 0;

    // 统计 01 和 10 的数量，以及 `?` 的个数
    for (ll i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '1') count_01++;
        if (s[i] == '1' && s[i + 1] == '0') count_10++;
    }
    for (char c : s) {
        if (c == '?') question_count++;
    }

    ll val_sum = 0;

    // 遍历字符串，尝试翻转每个字符
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '?') {
            // 把 '0' 翻转成 '1'，查看是否平衡
            ll new_01 = count_01, new_10 = count_10;
            if (i > 0 && s[i - 1] == '0') new_01++;  // "01" 可能增加
            if (i < n - 1 && s[i + 1] == '1') new_01++;  // "01" 可能增加
            if (i > 0 && s[i - 1] == '1') new_10--;  // "10" 可能减少
            if (i < n - 1 && s[i + 1] == '0') new_10--;  // "10" 可能减少

            if (new_01 == new_10) val_sum++;
        }

        if (s[i] == '1' || s[i] == '?') {
            // 把 '1' 翻转成 '0'，查看是否平衡
            ll new_01 = count_01, new_10 = count_10;
            if (i > 0 && s[i - 1] == '0') new_01--;  // "01" 可能减少
            if (i < n - 1 && s[i + 1] == '1') new_01--;  // "01" 可能减少
            if (i > 0 && s[i - 1] == '1') new_10++;  // "10" 可能增加
            if (i < n - 1 && s[i + 1] == '0') new_10++;  // "10" 可能增加

            if (new_01 == new_10) val_sum++;
        }
    }

    // 计算答案
    ll result = val_sum * power2[question_count] % MOD;
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
