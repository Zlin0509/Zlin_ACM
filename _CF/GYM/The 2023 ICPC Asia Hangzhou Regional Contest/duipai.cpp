#include<iostream>
#include<stdlib.h>  // 在 Unix 系统下包含 system 函数需要使用 <stdlib.h>

using namespace std;

int main() {
    int t = 100000;
    for (int i = 1; i <= t; i++) {
        system("./data > data.txt");
        system("./ac < data.txt > ac.txt");
        system("./wa < data.txt > wa.txt");
        cout << "test " << i << " :";
        if (system("diff ac.txt wa.txt")) {
            cout << "WA" << '\n';
            break;
        } else cout << "AC" << '\n';
    }
    return 0;
}