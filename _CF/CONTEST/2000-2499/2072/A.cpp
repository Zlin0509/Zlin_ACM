#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t; // 读取测试案例的个数
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p; // 读取 n, k, p

        // 如果 k 超出了能达到的范围，则输出 -1
        if (k < -n * p || k > n * p) {
            cout << -1 << endl;
        } else {
            // 计算需要的操作次数
            int abs_k = abs(k);
            int operations = 0;

            // 贪心地尽量用最大的 p 或者 -p 来接近 k
            while (abs_k > 0 && operations < n) {
                if (abs_k >= p) {
                    abs_k -= p;
                } else {
                    abs_k = 0;  // 剩下的部分可以用一次操作处理
                }
                operations++;
            }

            cout << operations << endl;
        }
    }
    return 0;
}
