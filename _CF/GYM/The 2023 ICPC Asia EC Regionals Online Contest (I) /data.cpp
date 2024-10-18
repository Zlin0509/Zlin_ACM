#include <iostream>
#include <random>
#include <string>

using namespace std;

// 生成一个随机字符串，包含大小写字母、数字和问号
string String(int length) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789?";
    random_device rd; // 随机设备
    mt19937 gen(rd()); // 使用Mersenne Twister算法
    uniform_int_distribution<> dis(0, characters.size() - 1); // 定义一个分布

    string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += characters[dis(gen)]; // 从字符集随机选择字符
    }

    return randomString;
}

int main() {
    srand(time(0));
    int n = random() % 10;
    cout << n << '\n';
    cout << String(n);
    return 0;
}