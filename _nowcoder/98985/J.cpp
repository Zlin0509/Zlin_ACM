//
// Created by 27682 on 2024/12/31.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string BASE64_CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

std::string octalToBase64(const std::string &octal) {
    std::string binary;
    for (char c: octal) {
        int octDigit = c - '0';
        binary += std::bitset<3>(octDigit).to_string(); // 八进制到 3 位二进制
    }

    while (binary.size() % 6 != 0) {
        binary += '0'; // 补足到 6 的倍数
    }

    std::string base64;
    for (size_t i = 0; i < binary.size(); i += 6) {
        std::string chunk = binary.substr(i, 6);
        int decimalValue = std::stoi(chunk, nullptr, 2); // 二进制转十进制
        base64 += BASE64_CHARS[decimalValue]; // 映射到 Base64 字符
    }

    return base64;
}

inline void Zlin() {
    int n;
    cin >> n;
    string x;
    while (n--) x += "2025";
    cout << octalToBase64(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}