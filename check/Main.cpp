//
// Created by Zlin on 2025/2/7.
//

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    for (int i = 1; i <= ttt; i++) {
        system("C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.exe > data.txt");
        system(
            "C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/WA.exe < C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.txt > WA.txt");
        system(
            "C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/AC.exe < C:/Users/27682/Desktop/Zlin_ACM/cmake-build-debug/data.txt > AC.txt");
        cout << "test " << i << ':';
        if (system(
            "fc AC.txt WA.txt")) {
            cout << "WA" << '\n';
            break;
        }
        cout << "AC" << '\n';
    }
    return 0;
}
