//
// Created by Zlin on 2025/2/7.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 10000;
    // cin >> ttt;
    for (int i = 1; i <= ttt; i++) {
        system("C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.exe > data.txt");
        system(
            "C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/WA.exe < C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.txt > WA.txt");
        // cout << "test " << i << ':';
        // // 检查 WA.txt 第一行是否为 -1
        // ifstream fin("C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/WA.txt");
        // string output_line;
        // if (!getline(fin, output_line)) {
        //     cout << "WA (empty output)" << '\n';
        //     break;
        // }
        // output_line.erase(remove_if(output_line.begin(), output_line.end(), ::isspace), output_line.end());
        // if (output_line != "-1") {
        //     cout << "WA (output: " << output_line << ")" << endl;
        //     break;
        // }
        // cout << "AC" << endl;
        system(
            "C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/AC.exe < C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.txt > AC.txt");
        if (system("fc AC.txt WA.txt")) break;
    }
    return 0;
}
