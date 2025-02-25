#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;  // 读取测试用例个数
    while (t--) {
        int n;
        string s;
        cin >> n >> s;  // 读取字符串的长度和字符串本身
        int x = 0;
        for (auto it: s)
            if (it == '_')
                ++x;
        long long ans = 0;
        int y = n - x;
        ans = 1ll * x * (y / 2) * (y / 2 + y % 2);
        cout << ans << endl;
    }
    return 0;
}
