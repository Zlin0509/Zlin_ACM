#include<iostream>
#include<stdlib.h>  // 在 Unix 系统下包含 system 函数需要使用 <stdlib.h>

using namespace std;

int main() {
    int t = 1000;
    for (int i = 1; i <= t; i++) {
        system("./data > data.txt");
        system("./a < data.txt > a.txt");
        system("./b < data.txt > b.txt");
        cout << "test " << i << " :";
        if (system("diff a.txt b.txt")) {
            cout << "WA" << '\n';
            break;
        } else cout << "AC" << '\n';
    }
    return 0;
}